// // WastePlant.h
// #ifndef WASTEPLANT_H
// #define WASTEPLANT_H

// #include "Plant.h"

// // Forward declarations
// class PlantState;
// class WastePlantOperationalState;
// class WastePlantMaintenanceState;
// class WastePlantShutdownState;

// class WastePlant : public Plant {
// public:
//     WastePlant(const std::string& name, const std::string& loc, int cap);
//     ~WastePlant();

//     // Plant operations
//     void startPlant() override;
//     void stopPlant() override;
//     void performMaintenance() override;
//     std::string getPlantDetails() const override;

 
//     void startOperation() override;
//     void stopOperation() override;
//     void performInspection() override;
//     std::string getBuildingDetails() const override;

//     // Waste-specific operations
//     void recycleWaste();
//     void handleWasteOverflow();
//     void startWasteProcessing();

//     // Implementing Plant's pure virtual functions
//    // void handleFault() override;
//    // void adjustParameters(double factor) override;

// private:
//     int wasteCapacity;
//     double recyclingRate;
//     // Removed PlantState* wasteState to prevent double management
// };

// #endif // WASTEPLANT_H

// WastePlant.h
#ifndef WASTEPLANT_H
#define WASTEPLANT_H

#include "Plant.h"

// Forward declarations
class PlantState;
class WastePlantOperationalState;
class WastePlantMaintenanceState;
class WastePlantShutdownState;
class WastePlant : public Plant {
public:
    WastePlant(const std::string& name, const std::string& loc, int cap);
    ~WastePlant();

    // Plant operations
    void startPlant() override;
    void stopPlant() override;
    void performMaintenance() override;
    std::string getPlantDetails() const override;

    void startOperation() override;
    void stopOperation() override;
    void performInspection() override;
    std::string getBuildingDetails() const override;
    void print() const override;
    void construct() override;
    void maintain() override;
    void startProduction() override;
    void stopProduction() override;
    void hireWorker(const std::string& workerName) override;
    void allocateJobs() override;
    int getNumberOfWorkers() const override;

    // Waste-specific operations
    void recycleWaste();
    void handleWasteOverflow();
    void startWasteProcessing();

private:
    int wasteCapacity;
    double recyclingRate;
    std::vector<std::string> workers;
    int numberOfWorkers;
};

#endif // WASTEPLANT_H

// SewagePlant.h
#ifndef SEWAGEPLANT_H
#define SEWAGEPLANT_H

#include <string>
#include "SewagePlantState.h"
#include "Plant.h"

// Forward declarations to reduce dependencies
class SewagePlantOperationalState;
class SewagePlantShutdownState;
class SewagePlantMaintenanceState;

class SewagePlant : public Plant
{
private:
    int treatmentCapacity;
    int treatedVolume;

public:
    // Constructor
    SewagePlant(const std::string &name, const std::string &loc, int cap);

    // Destructor
    ~SewagePlant() override;

    // Plant virtual functions.
    void startPlant() override;
    void stopPlant() override;
    void performMaintenance() override;
    void startOperation() override;       // Implemented
    void stopOperation() override;        // Implemented
    void performInspection() override;    // Implemented
    std::string getPlantDetails() const override;
    std::string getBuildingDetails() const override; // Implemented

    // Additional methods
    void startSewageTreatment();
    void increaseCapacity(int newCapacity);
    SewagePlantState* getSewageState();

       // Implement missing pure virtual functions
    void print() const override;
    void construct() override;
    void maintain() override;
    void startProduction() override;
    void stopProduction() override;
    void hireWorker(const std::string& workerName) override;
    void allocateJobs() override;
    int getNumberOfWorkers() const override;
};

#endif // SEWAGEPLANT_H

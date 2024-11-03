// Plant.h
#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <vector>
#include <algorithm> // For std::remove and std::find
#include "IndustrialBuilding.h"

// Forward declarations
class PlantsManager;
class PlantState;

class Plant : public IndustrialBuilding {
public:
    Plant(const std::string& name, const std::string& loc, int cap)
        : IndustrialBuilding(name, loc, cap), currentStatus(nullptr),
          currentDemand(0), currentOutput(0), faultProbability(0.01) {}
    
    virtual ~Plant(); // Declare destructor
    
    // Subject methods
    void attachManager(PlantsManager* manager);
    void detachManager(PlantsManager* manager);
    void notifyManagers();
    
    // Plant operations
    virtual void startPlant() = 0;
    virtual void stopPlant() = 0;
    virtual void performMaintenance() = 0;
    virtual std::string getPlantDetails() const = 0;
    // virtual void triggerFault(const std::string& faultType) = 0; 
    // Implementing IndustrialBuilding's pure virtual functions
    virtual void startOperation() = 0;
    virtual void stopOperation() = 0;
    virtual void performInspection() = 0;
    virtual std::string getBuildingDetails() const = 0;
    
    // State management
    void setState(PlantState* newState);
    PlantState* getState() const;
    
    // // Fault handling
    // virtual void handleFault() = 0;
    
    // Adjust parameters based on policy impact
    //virtual void adjustParameters(double factor) = 0;
    
    // Set and adjust demand
   // void setDemand(int newDemand);
    //int getDemand() const { return currentDemand; }
    
    // Adjust fault probability
    void adjustFaultProbability(double factor) {
        faultProbability *= factor;
        if (faultProbability < 0.0) faultProbability = 0.0;
        if (faultProbability > 1.0) faultProbability = 1.0;
    }
    double getFaultProbability() const { return faultProbability; }
    
protected:
    int currentDemand;
    int currentOutput;
    double faultProbability;
    
private:
    PlantState* currentStatus;
    std::vector<PlantsManager*> managers;
    
    // Method to check demand vs capacity
    void checkAndHandleDemand();
};

#endif // PLANT_H

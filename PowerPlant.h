#ifndef POWERPLANT_H
#define POWERPLANT_H

#include <string>
#include <memory>
#include "Plant.h"
#include "PlantState.h"

class PlantState;
class Operational;
class Overload;
//class PartialState;
class PowerPlantShutdown;

class PowerPlant : public Plant {
private:
    double powerOutput; 
     int capacity; 
    double output;

public:

    PowerPlant(const std::string& name, const std::string& loc, int cap);
    ~PowerPlant();

    // Implement Plant's pure virtual methods
    void startPlant() override;
    void stopPlant() override;
    void performMaintenance() override;
    void startOperation() override;           // Added implementation
    void stopOperation() override;            // Added implementation
    void performInspection() override;        // Added implementation
    std::string getPlantDetails() const override;
    std::string getBuildingDetails() const override; // Added implementation

   
    void generateElectricity();
    void handlePowerOverload();
    void changePowerOutput(double output);
    void reduceOutput(double percentage);
    
};

#endif // POWERPLANT_H

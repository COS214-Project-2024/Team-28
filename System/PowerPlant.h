// PowerPlant.h
#ifndef POWERPLANT_H
#define POWERPLANT_H

#include <string>
#include <memory>
#include "Plant.h"
#include "PlantState.h"

// Forward declarations of state classes
class PowerPlantOperationalState;
class PowerPlantOverloadState;
class PowerPlantShutdownState;

class PowerPlant : public Plant
{
private:
    double powerOutput;  // Current power output in MW
    int capacity;        // Maximum capacity in MW
    double output;       // Desired power output in MW

public:
    PowerPlant(const std::string &name, const std::string &loc, int cap);
    ~PowerPlant();

    // Implement Plant's pure virtual methods
    void startPlant() override;
    void stopPlant() override;
    void performMaintenance() override;
    void startOperation() override;    // Implemented
    void stopOperation() override;     // Implemented
    void performInspection() override; // Implemented
    std::string getPlantDetails() const override;
    std::string getBuildingDetails() const override; // Implemented

    void generateElectricity();
    void handlePowerOverload();
    void changePowerOutput(double output);
    void reduceOutput(double percentage);

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

#endif // POWERPLANT_H

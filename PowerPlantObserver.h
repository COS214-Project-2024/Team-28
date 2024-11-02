// PowerPlantObserver.h
#ifndef POWERPLANTOBSERVER_H
#define POWERPLANTOBSERVER_H

#include "PlantsManager.h"
#include "PlantState.h" 
#include "PowerPlant.h"
#include <iostream>

class PowerPlant;
class PowerPlantObserver : public PlantsManager {
public:
    // Constructor accepting a manager name
    PowerPlantObserver(const std::string& managerName)
        : PlantsManager(managerName), faultActive(false), maintenanceInProgress(false) {}
    virtual ~PowerPlantObserver(){}
    // Override methods from PlantsManager
    void update(Plant* plant, PlantState* state) override;
    void initiateFaultHandling(const std::string& faultType) override;
    void restorePlantOperations() override;
    void performRoutineMaintenance(Plant* plant) override; // Corrected signature
    void changeState(Plant* plant, const std::string& newState) override;
    void reportStatus() const override;
    void allocateResources() override;

private:
    bool faultActive;
    bool maintenanceInProgress;
};

#endif // POWERPLANTOBSERVER_H

// PowerPlantObserver.h
#ifndef POWERPLANTOBSERVER_H
#define POWERPLANTOBSERVER_H

#include "PlantsManager.h"
#include "PlantState.h" 
#include "PowerPlant.h"
#include "PlantStateHandler.h"     // Added
#include "PowerHandler.h"     // Added
#include <iostream>
#include <string>

class PowerPlantObserver : public PlantsManager {
public:
    // Constructor accepting a manager name
    PowerPlantObserver(const std::string& managerName)
        : PlantsManager(managerName), faultActive(false), maintenanceInProgress(false) {
        
        faultHandlerChain = new PowerHandler();
        // If there are more handlers, set them here using setNext
        // e.g., faultHandlerChain->setNext(new WaterHandler());
    }

    // Destructor
    virtual ~PowerPlantObserver() {
        delete faultHandlerChain;
    }

    // Override methods from PlantsManager
    void update(Plant* plant, PlantState* state) override;
    void initiateFaultHandling(const std::string& faultType) override;
    void restorePlantOperations() override;
    void performRoutineMaintenance(Plant* plant) override; // Corrected signature
    void changeState(Plant* plant, const std::string& newState) override;
    void reportStatus() const override;
    void allocateResources() override;

    // Specific method to handle power faults
    void handlePowerFault(const std::string& faultType);

private:
    PlantStateHandler* faultHandlerChain; // Head of the fault handler chain
    bool faultActive;
    bool maintenanceInProgress;
};

#endif // POWERPLANTOBSERVER_H

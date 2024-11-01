// SewagePlantObserver.h
#ifndef SEWAGEPLANTOBSERVER_H
#define SEWAGEPLANTOBSERVER_H

#include "PlantsManager.h"
#include "PlantState.h" // Ensure complete type is included
#include "SewagePlant.h"
#include <iostream>

class SewagePlantObserver : public PlantsManager {
public:
    // Constructor 
    SewagePlantObserver(const std::string& managerName)
        : PlantsManager(managerName), faultActive(false) {}

    // Override methods from PlantsManager
    void update(Plant* plant, PlantState* state) override;
    void initiateFaultHandling(const std::string& faultType) override;
    void restorePlantOperations() override;
    void performRoutineMaintenance(Plant* plant) override;
    void changeState(Plant* plant, const std::string& newState) override;
    void reportStatus() const override;
    void allocateResources() override;

private:
    bool faultActive;
};

#endif // SEWAGEPLANTOBSERVER_H

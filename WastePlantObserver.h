// WastePlantObserver.h
#ifndef WASTEPLANTOBSERVER_H
#define WASTEPLANTOBSERVER_H

#include "PlantsManager.h"
#include "PlantState.h" // Ensure complete type is included
#include "WastePlant.h" // Include if WastePlant is used within the observer
#include "WasteHandler.h"
#include <iostream>

// Forward declaration to reduce dependencies
class WastePlant;

class WastePlantObserver : public PlantsManager
{
public:
    // Constructor accepting a manager name
    WastePlantObserver(const std::string &managerName)
        : PlantsManager(managerName), faultActive(false), maintenanceInProgress(false)
    {
        wasteHandlerChain = new WasteHandler();
    }

    // Destructor
    virtual ~WastePlantObserver()
    {
        delete wasteHandlerChain;
    }

    // Override methods from PlantsManager
    void update(Plant *plant, PlantState *state) override;
    void initiateFaultHandling(const std::string &faultType) override;
    void restorePlantOperations() override;
    void performRoutineMaintenance(Plant *plant) override;
    void changeState(Plant *plant, const std::string &newState) override;
    void reportStatus() const override;
    void allocateResources() override;
    void handleWaste(const std::string &faultType);

private:
    PlantStateHandler *wasteHandlerChain;
    bool faultActive;           // Indicates if a fault is currently active
    bool maintenanceInProgress; // Indicates if maintenance is currently in progress
};

#endif // WASTEPLANTOBSERVER_H

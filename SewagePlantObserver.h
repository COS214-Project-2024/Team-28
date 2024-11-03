// SewagePlantObserver.h
#ifndef SEWAGEPLANTOBSERVER_H
#define SEWAGEPLANTOBSERVER_H
#include <iostream>
#include <string>
#include "PlantStateHandler.h"
#include "PlantState.h" 
#include "PlantsManager.h"
#include "SewageHandler.h"
#include <string>

class SewagePlantObserver : public PlantsManager {
public:
    // Constructor
    SewagePlantObserver(const std::string& managerName)
        : PlantsManager(managerName), faultActive(false), maintenanceInProgress(false) {
         blockageHandlerChain = new SewageHandler();

        }

    // Destructor
    virtual ~SewagePlantObserver() {
        delete blockageHandlerChain;
    }

    // PlantManager virtual function
    void update(Plant* plant, PlantState* state) override;

    // Additional functions (do not use 'override' if not in base class)
    void initiateFaultHandling(const std::string& faultType) override;
    void restorePlantOperations() override;
    void performRoutineMaintenance(Plant* plant) override;
    void changeState(Plant* plant, const std::string& newState) override;
    void reportStatus() const override;
    void allocateResources() override;
     void handleSewageBlockage(const std::string& faultType);
private:
    PlantStateHandler* blockageHandlerChain;
    bool faultActive;
    bool maintenanceInProgress; 
};

#endif // SEWAGEPLANTOBSERVER_H

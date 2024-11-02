// SewagePlantObserver.h
#ifndef SEWAGEPLANTOBSERVER_H
#define SEWAGEPLANTOBSERVER_H

#include "PlantsManager.h"
#include <string>

class SewagePlantObserver : public PlantsManager {
public:
    // Constructor
    SewagePlantObserver(const std::string& managerName)
        : PlantsManager(managerName), faultActive(false), maintenanceInProgress(false) {}

    // Destructor
    virtual ~SewagePlantObserver() {}

    // PlantManager virtual function
    void update(Plant* plant, PlantState* state) override;

    // Additional functions (do not use 'override' if not in base class)
    void initiateFaultHandling(const std::string& faultType) override;
    void restorePlantOperations() override;
    void performRoutineMaintenance(Plant* plant) override;
    void changeState(Plant* plant, const std::string& newState) override;
    void reportStatus() const override;
    void allocateResources() override;

private:
    bool faultActive;
    bool maintenanceInProgress; 
};

#endif // SEWAGEPLANTOBSERVER_H

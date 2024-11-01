// WaterPlantObserver.h
#ifndef WATERPLANTOBSERVER_H
#define WATERPLANTOBSERVER_H

#include "PlantsManager.h"
#include "PlantState.h"  
#include "WaterPlant.h"
#include <iostream>


class WaterPlant;

class WaterPlantObserver : public PlantsManager {
public:
  
    WaterPlantObserver(const std::string& managerName)
        : PlantsManager(managerName), faultActive(false) {}

    
    virtual ~WaterPlantObserver() {}

 
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

#endif // WATERPLANTOBSERVER_H

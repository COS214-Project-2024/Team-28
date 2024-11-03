#ifndef WATERPLANTOBSERVER_H
#define WATERPLANTOBSERVER_H

#include "PlantsManager.h"
#include "WaterPlant.h"
#include <string>

class WaterPlantObserver : public PlantsManager {
public:
    WaterPlantObserver(const std::string& managerName);
    ~WaterPlantObserver();

    void update(Plant* plant, PlantState* state) override;
    void initiateFaultHandling(const std::string& faultType) override;
    void restorePlantOperations() override;
    void performRoutineMaintenance(Plant* plant) override;
    void changeState(Plant* plant, const std::string& newState) override;
    void reportStatus() const override;
    void allocateResources() override;
};

#endif // WATERPLANTOBSERVER_H
#ifndef WATERPLANTOBSERVER_H
#define WATERPLANTOBSERVER_H

#include "PlantsManager.h"
#include "WaterPlant.h"
#include "WaterHandler.h"
#include <string>

class WaterPlantObserver : public PlantsManager
{
private:
    PlantStateHandler *waterHandlerChain;
    bool faultActive;
    bool maintenanceInProgress;

public:
    WaterPlantObserver(const std::string &managerName)
        : PlantsManager(managerName), faultActive(false), maintenanceInProgress(false)
    {
        waterHandlerChain = new WaterHandler();
    };
    ~WaterPlantObserver()
    {
        delete waterHandlerChain;
    };

    void update(Plant *plant, PlantState *state) override;
    void initiateFaultHandling(const std::string &faultType) override;
    void restorePlantOperations() override;
    void performRoutineMaintenance(Plant *plant) override;
    void changeState(Plant *plant, const std::string &newState) override;
    void reportStatus() const override;
    void allocateResources() override;
    void handleWater(const std::string &faultType);
};

#endif // WATERPLANTOBSERVER_H
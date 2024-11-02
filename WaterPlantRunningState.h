#ifndef WATERPLANTRUNNINGSTATE_H
#define WATERPLANTRUNNINGSTATE_H

#include "WaterPlantState.h"

class WaterPlantRunningState : public WaterPlantState {
public:
    WaterPlantRunningState();
    ~WaterPlantRunningState() override;

    void handleWaterState() override;
    void handleState(Plant* plant) override;
    std::string getStateName() override;
};

#endif // WATERPLANTRUNNINGSTATE_H
#ifndef WATERPLANTRUNNINGSTATE_H
#define WATERPLANTRUNNINGSTATE_H

#include "WaterPlantState.h"
#include "WaterPlantTreatmentState.h"

class WaterPlantRunningState : public WaterPlantState 
{
    private:
        WaterPlantTreatmentState *treatmentState;
        bool isRunning;
    public:
        WaterPlantRunningState(WaterPlantTreatmentState *treatmentState);
        //void handlePowerState() override;
        ~WaterPlantRunningState();
};
#endif
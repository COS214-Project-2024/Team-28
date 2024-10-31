#ifndef WATERPLANTRUNNINGSTATE_H
#define WATERPLANTRUNNINGSTATE_H

#include "PowerPlantState.h"
#include "WaterPlantTreatmentState.h"

class WaterPlantRunningState : public PowerPlantState
{
    private:
        WaterPlantTreatmentState *treatmentState;
        bool isRunning;
    public:
        WaterPlantRunningState(WaterPlantTreatmentState *treatmentState);
        void handlePowerState() override;
        ~WaterPlantRunningState();
};
#endif
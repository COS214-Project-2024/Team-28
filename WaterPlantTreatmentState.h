#ifndef WATERPLANTTREATMENTSTATE_H
#define WATERPLANTTREATMENTSTATE_H
#include "WaterPlantState.h"
#include "WaterPlantContaminatedState.h"

class WaterPlantTreatmentState : public WaterPlantState
{
    private:
        bool isTreating;
        WaterPlantContaminatedState *contaminatedState;
    public:
        WaterPlantTreatmentState(WaterPlantContaminatedState *contaminatedState);
        void handleWaterState() override;
        ~WaterPlantTreatmentState();
};
#endif
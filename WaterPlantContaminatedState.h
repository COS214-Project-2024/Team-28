#ifndef WATERPLANTCONTAMINATEDSTATE_H
#define WATERPLANTCONTAMINATEDSTATE_H
#include "WaterPlantState.h"

class WaterPlantContaminatedState : public WaterPlantState
{
    private:
        bool isContaminated;
    public:
        WaterPlantContaminatedState(bool isContaminated);
        void handleWaterState() override;
        WaterPlantContaminatedState();
};
#endif
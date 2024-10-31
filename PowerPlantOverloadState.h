#ifndef POWERPLANTOVERLOADSTATE_H
#define POWERPLANTOVERLOADSTATE_H
#include "PowerPlantState.h"

class PowerPlantOverloadState : public PowerPlantState
{
    private:
        int overloadThreshold;
    public:
        PowerPlantOverloadState(int threshold);
        void handlePowerState() override;
        void restoreNormalOperations();
        void update();
};
#endif
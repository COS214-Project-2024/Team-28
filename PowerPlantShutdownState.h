#ifndef POWERPLANTSHUTDOWNSTATE_H
#define POWERPLANTSHUTDOWNSTATE_H
#include "PowerPlantState.h"
#include "PowerPlantOperationalState.h"
class PowerPlantShutdownState : public PowerPlantState
{
private:
    PowerPlantOperationalState *operationalState;

public:
    PowerPlantShutdownState(PowerPlantOperationalState *operationalState);
    void handlePowerState() override;
    void restoreNormalOperations();
    void update();
    ~PowerPlantShutdownState();
};
#endif
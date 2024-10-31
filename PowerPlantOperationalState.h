#ifndef POWERPLANTOPERATIONALSTATE_H
#define POWERPLANTOPERATIONALSTATE_H
#include "PowerPlantState.h"
#include "PowerPlantOverloadState.h"

class PowerPlantOperationalState : public PowerPlantState
{
private:
    PowerPlantOverloadState *overload;
    bool isOperational;

public:
    PowerPlantOperationalState(PowerPlantOverloadState *overload, bool isOperational);
    ~PowerPlantOperationalState();
    void handlePowerState() override;
};
#endif

#include "PowerPlantState.h"


PowerPlantState::PowerPlantState(/* args */)
{
    isOperational = true;
}

void PowerPlantState::handleState()
{
    handlePowerState();
}

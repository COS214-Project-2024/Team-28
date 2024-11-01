// PowerPlantShutdownState.h
#ifndef POWERPLANTSHUTDOWNSTATE_H
#define POWERPLANTSHUTDOWNSTATE_H

#include "PowerPlantState.h"
#include "Plant.h" // Assuming Plant is defined here or elsewhere
#include <string>

class PowerPlantShutdownState : public PowerPlantState
{
public:
    PowerPlantShutdownState() = default;
    ~PowerPlantShutdownState() override = default;

    void handleState(Plant* plant) override;
    std::string getStateName()  override; // Added const
};

#endif // POWERPLANTSHUTDOWNSTATE_H

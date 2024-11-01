// PowerPlantOperationalState.h
#ifndef POWERPLANTOPERATIONALSTATE_H
#define POWERPLANTOPERATIONALSTATE_H

#include "PowerPlantState.h"
#include "PowerPlantOverloadState.h"
#include "Plant.h" // Ensure Plant is included if needed
#include <string>
#include <iostream>
using namespace std;

class PowerPlantOperationalState : public PowerPlantState
{
private:
    PowerPlantOverloadState *overload;
    bool isOperational;

public:
    PowerPlantOperationalState(PowerPlantOverloadState *overload, bool isOperational)
        : overload(overload), isOperational(isOperational) {}
    
    PowerPlantOperationalState() : overload(nullptr), isOperational(false) {}

    ~PowerPlantOperationalState() override;

    void handleState(Plant* plant) override;
    std::string getStateName()  override; 
};

#endif // POWERPLANTOPERATIONALSTATE_H

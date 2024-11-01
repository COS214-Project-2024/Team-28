
#ifndef POWERPLANTSTATE_H
#define POWERPLANTSTATE_H
#include "PlantState.h"

class PowerPlantState: public PlantState
{
private:
public:
    PowerPlantState() = default;
    virtual void handleState(Plant* plant) = 0;
    virtual std::string getStateName()= 0; 
    virtual ~PowerPlantState() = default;
};

#endif // POWERPLANTSTATE_H

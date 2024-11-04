
#ifndef POWERPLANTSTATE_H
#define POWERPLANTSTATE_H
#include "PlantState.h"

class PowerPlantState: public PlantState
{
private:
public:
    PowerPlantState() = default;
    void handleState(Plant* plant) override;
    std::string getStateName() override; 
    virtual ~PowerPlantState() = default;
};

#endif // POWERPLANTSTATE_H

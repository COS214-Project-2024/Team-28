#ifndef WATERPLANTSTATE_H
#define WATERPLANTSTATE_H
#include "PlantState.h"

class WaterPlantState: public PlantState
{
private:

public:
    WaterPlantState();
    virtual void handleWaterState() = 0;
    ~WaterPlantState();
};
#endif
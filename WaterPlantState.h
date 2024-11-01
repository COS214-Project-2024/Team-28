#ifndef WATERPLANTSTATE_H
#define WATERPLANTSTATE_H
#include "PlantState.h"

class WaterPlantState: public PlantState
{
private:
    /* data */
public:
    WaterPlantState(/* args */);
    virtual void handleWaterState() = 0;
    ~WaterPlantState();
};
#endif
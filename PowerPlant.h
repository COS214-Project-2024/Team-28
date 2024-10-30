#ifndef POWERPLANT_H
#define POWERPLANT_H
#include <string>
#include "PowerPlantState.h"
#include "Plant.h"

class PowerPlant: public Plant
{
private:
    int powerOutput;
    PowerPlantState *powerState;

public:
    PowerPlant(/* args */);
    ~PowerPlant();
    void generateElectricity();
    void handlePowerOverload();
    void changePowerOutput(int output);
    PowerPlantState* getPowerState();
};
#endif


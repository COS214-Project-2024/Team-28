#ifndef POWERPLANTSTATE_H
#define POWERPLANTSTATE_H

class PowerPlantState
{
private:
    /* data */
public:
    PowerPlantState(/* args */);
    virtual void handlePowerState() = 0;
    ~PowerPlantState();
};
#endif
#ifndef WATERPLANTSTATE_H
#define WATERPLANTSTATE_H

class WaterPlantState
{
private:
    /* data */
public:
    WaterPlantState(/* args */);
    virtual void handleWaterState() = 0;
    ~WaterPlantState();
};
#endif
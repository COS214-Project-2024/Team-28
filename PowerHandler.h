#ifndef POWERHANDLER_H
#define POWERHANDLER_H
#include <string>
#include "PlantStateHandler.h"

class PowerHandler : public PlantStateHandler
{
private:
    string powerPlantName;
public:
    PowerHandler(/* args */);
    ~PowerHandler();
    void restorePlantOperations() override;
    void performRoutineMaintenance() override;
    void changeState(string newState) override;
};
#endif
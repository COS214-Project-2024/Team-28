#ifndef WATERHANDLER_H
#define WATERHANDLER_H
#include <string>
#include "PlantStateHandler.h"

class WaterHandler : public PlantStateHandler
{
private:
    string waterPlantName;

public:
    WaterHandler(/* args */);
    ~WaterHandler();
    void restorePlantOperations() override;
    void performRoutineMaintenance() override;
    void changeState(string newState) override;
};

#endif
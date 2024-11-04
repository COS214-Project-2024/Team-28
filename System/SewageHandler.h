#ifndef SEWAGEHANDLER_H
#define SEWAGEHANDLER_H
#include <string>
#include "PlantStateHandler.h"

class SewageHandler : public PlantStateHandler
{
private:
    string sewagePlantName;
public:
    SewageHandler(/* args */);
    ~SewageHandler();
    void restorePlantOperations() override;
    void performRoutineMaintenance() override;
    void changeState(string newState) override;
};
#endif
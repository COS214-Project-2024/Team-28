#ifndef WASTEHANDLER_H
#define WASTEHANDLER_H
#include <string>
#include "PlantStateHandler.h"
#include "WastePlant.h"
using namespace std;

class WasteHandler : public PlantStateHandler
{
private:
    WastePlant *stationPointer;

public:
    WasteHandler(/* args */);
    ~WasteHandler();
    void restorePlantOperations() override;
    void performRoutineMaintenance() override;
    void changeState(string newState) override;
};
#endif

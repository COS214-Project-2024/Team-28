#ifndef WASSTEPLANT_H
#define WASSTEPLANT_H
#include <string>
#include "Plant.h"
#include "WastePlantState.h"

class WastePlant: public Plant
{
private:
    int wasteCapacity;
    double recyclingRate;
    WastePlantState *wasteState;
public:
    WastePlant(/* args */);
    ~WastePlant();
    void recycleWaste();
    void handleWasteOverflow();
    void startWasteProcessing();
    WastePlantState* getWasteState();
};
#endif


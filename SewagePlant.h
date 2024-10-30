#ifndef SEWAGEPLANT_H
#define SEWAGEPLANT_H
#include <string>
#include "SewagePlantState.h"
#include "Plant.h"

class SewagePlant : public Plant
{
private:
    int treatmentCapacity;
    int treatedVolume;
    SewagePlantState *sewageState;
public:
    void startSewageTreatment();
    void increaseCapacity(int newCapacity);
    SewagePlantState* getSewageState();
};

#endif
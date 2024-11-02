#ifndef WATERPLANT_H
#define WATERPLANT_H
#include <string>
#include "WaterPlantState.h"
#include "Plant.h"

class WaterPlant : public Plant
{
private:
    std::string purificationLevel;
    int NumberofLitres;
public:
    WaterPlant();
    ~WaterPlant();
    void startWaterTreatment();
    void distribureWater();
    void changePurificationLevel(std::string level);
    WaterPlantState* getWaterState(); 
};
#endif

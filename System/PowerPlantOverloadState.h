#ifndef POWERPLANTOVERLOADSTATE_H
#define POWERPLANTOVERLOADSTATE_H
#include "PowerPlantState.h"
#include <iostream>
using namespace std;

class PowerPlantOverloadState : public PowerPlantState
{
    private:
        int overloadThreshold;
    public:
        PowerPlantOverloadState(int threshold);
        //void handlePowerState() override;
        void restoreNormalOperations();
        void update();
        void handleState(Plant* plant) override;
    std::string getStateName()  override ;
};
#endif
// #ifndef WATERPLANTRUNNINGSTATE_H
// #define WATERPLANTRUNNINGSTATE_H

// #include "WaterPlantState.h"
// #include "WaterPlantTreatmentState.h"

// class WaterPlantRunningState : public WaterPlantState 
// {
//     private:
//         WaterPlantTreatmentState *treatmentState;
//         bool isRunning;
//     public:
//         WaterPlantRunningState();
//         //void handlePowerState() override;
//         ~WaterPlantRunningState();
// };
// #endif

#ifndef WATERPLANTRUNNINGSTATE_H
#define WATERPLANTRUNNINGSTATE_H

#include "WaterPlantState.h"

class WaterPlantRunningState : public WaterPlantState {
public:
    WaterPlantRunningState();
    ~WaterPlantRunningState() override;

    // Override pure virtual functions from WaterPlantState and PlantState
    void handleWaterState() override;
    void handleState(Plant* plant) override;
    std::string getStateName() override;
};

#endif // WATERPLANTRUNNINGSTATE_H
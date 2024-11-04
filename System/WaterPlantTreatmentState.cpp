#include "WaterPlantTreatmentState.h"
#include <iostream>

WaterPlantTreatmentState::WaterPlantTreatmentState(WaterPlantContaminatedState *contaminatedState) {
    this->contaminatedState = contaminatedState;
}

void WaterPlantTreatmentState::handleWaterState() {
    if (isTreating) {
        std::cout << "Water is being treated." << std::endl;
    } else {
        contaminatedState->handleWaterState();
    }
}

WaterPlantTreatmentState::~WaterPlantTreatmentState() {
    delete contaminatedState;
}

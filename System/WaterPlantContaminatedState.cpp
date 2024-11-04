#include "WaterPlantContaminatedState.h"
#include <iostream>

WaterPlantContaminatedState::WaterPlantContaminatedState(bool isContaminated) {
    this->isContaminated = isContaminated;
}

void WaterPlantContaminatedState::handleWaterState() {
    if (isContaminated) {
        std::cout << "Water is contaminated." << std::endl;
    } else {
        std::cout << "Water is not contaminated." << std::endl;
    }
}

WaterPlantContaminatedState::WaterPlantContaminatedState() {
    this->isContaminated = false;
}


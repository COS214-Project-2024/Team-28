// Operational.cpp
#include "PowerPlantOperationalState.h"
#include "Plant.h"

void PowerPlantOperationalState::handleState(Plant* plant) {
    std::cout << plant->getPlantDetails() << " is operating normally." << std::endl;
}

std::string PowerPlantOperationalState::getStateName() {
    return "Operating";
}
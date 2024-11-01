// Operating.cpp
#include "WastePlantOperationalState.h"
#include "Plant.h"

void WastePlantOperationalState::handleState(Plant* plant) {
    std::cout << plant->getPlantDetails() << " is operating normally." << std::endl;
}

std::string WastePlantOperationalState::getStateName() const {
    return "Operating";
}
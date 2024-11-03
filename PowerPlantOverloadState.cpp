#include "PowerPlantOverloadState.h"
#include "Plant.h"

void PowerPlantOverloadState::handleState(Plant* plant) {
    std::cout << plant->getPlantDetails() << " is Overloaded." << std::endl;
    // Additional logic for operating state can be added here
}

std::string PowerPlantOverloadState::getStateName()  {
    return "Overload";
}
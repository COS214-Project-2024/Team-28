
#include "WastePlantShutdownState.h"
#include "Plant.h"

void WastePlantShutdownState::handleState(Plant* plant) {
    std::cout << plant->getPlantDetails() << " is shutdown." << std::endl;
    // Additional logic for partial state can be added here
}
std::string WastePlantShutdownState::getStateName() const {
    return "Shutdown";
}
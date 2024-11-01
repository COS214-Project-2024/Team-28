#include "PowerPlantShutdown.h"

#include "Plant.h"

void PowerPlantShutdown::handleState(Plant* plant) {
    std::cout << plant->getPlantDetails() << " is shutdown." << std::endl;
    // Additional logic for operating state can be added here
}

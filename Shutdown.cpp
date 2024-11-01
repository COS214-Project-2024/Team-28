// Shutdown.cpp
#include "Shutdown.h"
#include "Plant.h"

void Shutdown::handleState(Plant* plant) {
    std::cout << plant->getPlantDetails() << " is shut down." << std::endl;
    // Additional logic for shutdown state can be added here
}

// // PowerPlantShutdownState
// #include "PowerPlantShutdownState.h"
// #include <iostream>
// #include <string>
// #include "Plant.h"

// void PowerPlantShutdownState ::handleState(Plant *plant)
// {
//   std::cout << plant->getPlantDetails() << " is shut down." << std::endl;
//   // Additional logic for shutdown state can be added here
// }
// std::string PowerPlantShutdownState::getStateName()
// {
//   return "Shutdown";
// }

// PowerPlantShutdownState::~PowerPlantShutdownState() {
//     // Destructor implementation
// }

#include "PowerPlantShutdownState.h"

PowerPlantShutdownState::PowerPlantShutdownState() {
    // Constructor implementation
}

PowerPlantShutdownState::~PowerPlantShutdownState() {
    // Destructor implementation
}

void PowerPlantShutdownState::handleState(Plant* plant) {
    // Implementation of handleState
}

std::string PowerPlantShutdownState::getStateName() {
    return "Shutdown";
}
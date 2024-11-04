// SewagePlantShutdownState.cpp
#include "SewagePlantShutdownState.h"
#include "SewagePlant.h"
#include <iostream>

void SewagePlantShutdownState::handleState(Plant* plant) {
    SewagePlant* sewagePlant = dynamic_cast<SewagePlant*>(plant);
    if (sewagePlant) {
        if (isFailed) {
            std::cout << sewagePlant->getPlantDetails() << " has encountered a failure and is shut down." << std::endl;
            // Implement failure-specific logic here, such as initiating maintenance
            // sewagePlant->performMaintenance(); // Uncomment if method exists
        } else {
            std::cout << sewagePlant->getPlantDetails() << " has been shut down for regular maintenance." << std::endl;
        }
    } else {
        std::cerr << "Error: Plant is not a SewagePlant." << std::endl;
    }
}

std::string SewagePlantShutdownState::getStateName() {
    return "Shutdown";
}

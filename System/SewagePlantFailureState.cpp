// SewagePlantFailureState.cpp
#include "SewagePlantFailureState.h"
#include "SewagePlant.h"
#include <iostream>

SewagePlantFailureState::~SewagePlantFailureState() {
    // Destructor implementation (if needed)
}

void SewagePlantFailureState::handleState(Plant* plant) {
    SewagePlant* sewagePlant = dynamic_cast<SewagePlant*>(plant);
    if (sewagePlant) {
        if (isFailed) {
            std::cout << sewagePlant->getPlantDetails() << " has encountered a failure." << std::endl;
            // Implement failure-specific logic here
            // For example, initiate shutdown or maintenance
            // sewagePlant->performMaintenance(); // Uncomment if method exists
        } else {
            std::cout << sewagePlant->getPlantDetails() << " failure flag is not active." << std::endl;
        }
    } else {
        std::cerr << "Error: Plant is not a SewagePlant." << std::endl;
    }
}

std::string SewagePlantFailureState::getStateName() {
    return "Failure";
}

// SewagePlantOperationalState.cpp
#include "SewagePlantOperationalState.h"
#include "SewagePlant.h" // To cast Plant* to SewagePlant*
#include <iostream>

void SewagePlantOperationalState::handleState(Plant* plant) {
    SewagePlant* sewagePlant = dynamic_cast<SewagePlant*>(plant);
    if (sewagePlant) {
        std::cout << sewagePlant->getPlantDetails() << " is operating normally." << std::endl;
        sewagePlant->startSewageTreatment();
    } else {
        std::cerr << "Error: Plant is not a SewagePlant." << std::endl;
    }
}

std::string SewagePlantOperationalState::getStateName() {
    return "Operating";
}

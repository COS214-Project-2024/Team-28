#include "PowerHandler.h"
#include <iostream>

PowerHandler::PowerHandler() {
    powerPlantName = "PowerPlant1";
}

PowerHandler::~PowerHandler() {}

void PowerHandler::restorePlantOperations() {
    std::cout << "Restoring operations for " << powerPlantName << std::endl;
}

void PowerHandler::performRoutineMaintenance() {
    std::cout << "Performing routine maintenance for " << powerPlantName << std::endl;
}

void PowerHandler::changeState(string newState) {
    std::cout << "Changing state to " << newState << " for " << powerPlantName << std::endl;
}



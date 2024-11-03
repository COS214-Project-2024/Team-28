#include "WaterHandler.h"
#include <iostream>

WaterHandler::WaterHandler() {
    waterPlantName = "WaterPlant1";
}

WaterHandler::~WaterHandler() {}

void WaterHandler::restorePlantOperations() {
    std::cout << "Restoring operations for " << waterPlantName << std::endl;
}

void WaterHandler::performRoutineMaintenance() {
    std::cout << "Performing routine maintenance for " << waterPlantName << std::endl;
}

void WaterHandler::changeState(string newState) {
    std::cout << "Changing state to " << newState << " for " << waterPlantName << std::endl;
}


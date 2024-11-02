#include "WaterPlantRunningState.h"
#include <iostream>

// Constructor
WaterPlantRunningState::WaterPlantRunningState() {
    // Initialization if needed
}

// Destructor
WaterPlantRunningState::~WaterPlantRunningState() {
    // Cleanup if needed
}

// Override handleWaterState method
void WaterPlantRunningState::handleWaterState() {
    std::cout << "Handling water state in running state." << std::endl;
    // Implement the logic for handling water state
}

// Override handleState method
void WaterPlantRunningState::handleState(Plant* plant) {
    //std::cout << plant->getPlantDetails() << " is running normally." << std::endl;
    // Implement the logic for handling plant state
}

// Override getStateName method
std::string WaterPlantRunningState::getStateName() {
    return "Running";
}
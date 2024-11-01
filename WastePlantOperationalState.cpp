// // Operating.cpp
// #include "WastePlantOperationalState.h"
// #include "Plant.h"
// #include <iostream>
// using namespace std;

// void WastePlantOperationalState::handleState(Plant* plant) {
//     std::cout << plant->getPlantDetails() << " is operating normally." << std::endl;
// }

// std::string WastePlantOperationalState::getStateName(){
//     return "Operating";
// }

// #include "WastePlantOperationalState.h"

// WastePlantOperationalState::WastePlantOperationalState() {
//     // Constructor implementation
// }

// WastePlantOperationalState::~WastePlantOperationalState() {
//     // Destructor implementation
// }

#include "WastePlantOperationalState.h"

WastePlantOperationalState::WastePlantOperationalState() {
    // Constructor implementation
}

WastePlantOperationalState::~WastePlantOperationalState() {
    // Destructor implementation
}

void WastePlantOperationalState::handleState(Plant* plant) {
    // Implementation of handleState
}

std::string WastePlantOperationalState::getStateName() {
    return "Operating";
}
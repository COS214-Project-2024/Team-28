#include "WastePlantShutdownState.h"
#include "Plant.h"
#include <iostream>
using namespace std;

void WastePlantShutdownState::handleState(Plant* plant) {
    std::cout << plant->getPlantDetails() << " is shutdown." << std::endl;
    // Additional logic for partial state can be added here
}
std::string WastePlantShutdownState::getStateName() {
    return "Shutdown";
}

#include "WastePlantShutdownState.h"

WastePlantShutdownState::WastePlantShutdownState() {
    // Constructor implementation
}

WastePlantShutdownState::~WastePlantShutdownState() {
    // Destructor implementation
}

#include "PowerPlant.h"
#include "PowerPlantOperationalState.h"
#include "PowerPlantOverloadState.h"
#include "PowerPlantShutdownState.h"
#include <iostream>
#include <memory>
#include <algorithm>


PowerPlant::PowerPlant(const std::string& name, const std::string& loc, int cap)
    : Plant(name, loc, cap), capacity(cap), output(0.0) {
    setState(new PowerPlantOperationalState());
}

PowerPlant::~PowerPlant(){

}
void PowerPlant::startOperation() {
    startPlant();
}

void PowerPlant::stopOperation() {
    stopPlant();
}

void PowerPlant::performInspection() {
    performMaintenance();
}

std::string PowerPlant::getBuildingDetails() const {
    return getPlantDetails();
}

std::string PowerPlant::getPlantDetails() const {
    return "Power Plant: " + name + ", Location: " + location + ", Capacity: " + std::to_string(capacity) + " MW";
}
// Start the power plant and transition to the Operational state
void PowerPlant::startPlant() {
    std::cout << "Starting Power Plant: " << getName()<< std::endl;
    setState(new PowerPlantOperationalState());
    notifyManagers();
}

void PowerPlant::stopPlant() {
    // Added Implementation: Prevent redundant shutdown
    if (getState() && getState()->getStateName() == "Shutdown") {
        std::cout << "PowerPlant " << getPlantDetails() << " is already in Shutdown state." << std::endl;
        return;
    }

    std::cout << "Stopping Power Plant: " << getName() << std::endl;
    setState(new PowerPlantShutdownState());
    notifyManagers();
}

// Perform maintenance and transition to the Operational state
void PowerPlant::performMaintenance() {
    std::cout << "Performing maintenance on Power Plant: " << getName() << std::endl;
    setState(new PowerPlantOperationalState());
    notifyManagers();
}

// Change the power output and handle potential overloads
void PowerPlant::changePowerOutput(double output) {
    powerOutput = output;
    std::cout << "Power Plant " << name << " power output changed to " << powerOutput << " MW." << std::endl;
    
    // Check if powerOutput exceeds capacity and handle overload
    if (powerOutput > capacity) {
        handlePowerOverload();
    }
}

// Generate electricity based on the current state
void PowerPlant::generateElectricity() {
    // if (Operational) {
    //     powerOutput = std::min(static_cast<double>(capacity), powerOutput); // Cast capacity to double
    //     std::cout << "Power Plant " << getName() << " is generating " << powerOutput << " MW of electricity." << std::endl;
    // } else if (powerState->getStateName() == "Overload") {
    //     handlePowerOverload();
    // } else if (powerState->getStateName() == "Shutdown") {
    //     powerOutput = 0.0;
    //     std::cout << "Power Plant " << name << " is shut down. No electricity generated." << std::endl;
    // }
}

// Handle overload by transitioning to the Overload state
void PowerPlant::handlePowerOverload() {
    std::cout << "Power Plant " << getName() << " is overloaded! Transitioning to Overload state." << std::endl;
    //powerState = std::make_unique<Overload>();
    powerOutput *= 0.8; // Example: Reduce power output by 20%
    std::cout << "Reduced power output to " << powerOutput << " MW to handle overload." << std::endl;
    notifyManagers();
}

// Reduce the power output by a given percentage
void PowerPlant::reduceOutput(double percentage) {
    powerOutput *= (1.0 - percentage / 100.0);
}

// // Get the current state of the power plant
// PowerPlantState* PowerPlant::getPowerState() const {
//     return powerState.get();
// }

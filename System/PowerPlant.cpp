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
    // } else if (this->getState() == "Overload") {
    //     handlePowerOverload();
    // } else if (powerState->getStateName() == "Shutdown") {
    //     powerOutput = 0.0;
    //     std::cout << "Power Plant " << name << " is shut down. No electricity generated." << std::endl;
    // }
}

// Handle overload by transitioning to the Overload state
void PowerPlant::handlePowerOverload() {
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

void PowerPlant::print() const {
    std::cout << "PowerPlant: " << getName() 
              << "\nLocation: " << getLocation() 
              << "\nCapacity: " << capacity 
              << "\nPower Output: " << powerOutput << std::endl;
}

void PowerPlant::construct() {
    // Empty implementation
}

void PowerPlant::maintain() {
    // Empty implementation
}

void PowerPlant::startProduction() {
    // Empty implementation
}

void PowerPlant::stopProduction() {
    // Empty implementation
}

void PowerPlant::hireWorker(const std::string& workerName) {
    // Empty implementation
}

void PowerPlant::allocateJobs() {
    // Empty implementation
}

int PowerPlant::getNumberOfWorkers() const {
    return 0; // Default implementation
}
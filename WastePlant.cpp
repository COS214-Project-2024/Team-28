
#include "WastePlant.h"
#include "WastePlantOperationalState.h"
#include "WastePlantMaintenanceState.h"
#include "WastePlantShutdownState.h"
#include "PlantState.h" 
#include <iostream>


WastePlant::WastePlant(const std::string& name, const std::string& loc, int cap)
    : Plant(name, loc, cap), wasteCapacity(cap), recyclingRate(0.0) {
    setState(new WastePlantOperationalState());
}


WastePlant::~WastePlant() {

}

void WastePlant::startPlant() {
    std::cout << "Starting Waste Plant: " << getName() << std::endl;
    setState(new WastePlantOperationalState());
    notifyManagers();
}

void WastePlant::stopPlant() {
    std::cout << "Stopping Waste Plant: " << getName() << std::endl;
    setState(new WastePlantShutdownState());
    notifyManagers();
}

void WastePlant::performMaintenance() {
    std::cout << "Performing maintenance on Waste Plant: " << getName() << std::endl;
    setState(new WastePlantMaintenanceState());
    notifyManagers();
}

std::string WastePlant::getPlantDetails() const {
    return "WastePlant: " + getName() + ", Location: " + getLocation() +
           ", Capacity: " + std::to_string(getCapacity()) +
           ", Current State: " + (getState() ? getState()->getStateName() : "Unknown");
}

// Implementing IndustrialBuilding  methods
void WastePlant::startOperation() {
    startPlant();
}

void WastePlant::stopOperation() {
    stopPlant();
}

void WastePlant::performInspection() {
    performMaintenance();
}

std::string WastePlant::getBuildingDetails() const {
    return getPlantDetails();
}

// Wastespecific ops
void WastePlant::recycleWaste() {
    std::cout << "Recycling waste in " << getName() << std::endl;

    if(capacity>0){
    capacity= capacity - (0.5* capacity);
    }
}

void WastePlant::handleWasteOverflow() {
    std::cout << "Handling waste overflow in " << getName() << std::endl;
     
}

void WastePlant::startWasteProcessing() {
    std::cout << "Starting waste processing in " << getName() << std::endl;
    // Implement waste processing logic here
}

// // Implementing Plant's pure virtual functions
// void WastePlant::handleFault() {
//     std::cout << "Handling fault in Waste Plant: " << getName() << std::endl;
//     // Implement fault handling logic, e.g., transition to Shutdown or PartialState
//     // For example, transition to Shutdown
//     stopPlant();
// }

// void WastePlant::adjustParameters(double factor) {
//     std::cout << "Adjusting parameters of Waste Plant: " << getName() << " by factor " << factor << std::endl;
//     // Implement parameter adjustment based on policy impact
//     // For example, adjust fault probability
//     adjustFaultProbability(factor);
//     // Adjust capacity or other attributes if necessary
//}

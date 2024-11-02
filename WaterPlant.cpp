#include "WaterPlant.h"
#include "WaterPlantRunningState.h"
#include <iostream>

// Constructor
WaterPlant::WaterPlant(const std::string &name, const std::string &loc, int cap)
    : Plant(name, loc, cap), purificationLevel("Low"), NumberofLitres(0) {
    setState(new WaterPlantRunningState());
    std::cout << "WaterPlant " << getPlantDetails() << " constructed and is now operational." << std::endl;
}

// Destructor
WaterPlant::~WaterPlant() {
    delete getState();
}

// Start water treatment process
void WaterPlant::startWaterTreatment() {
    std::cout << "Water treatment started at WaterPlant " << getPlantDetails() << "." << std::endl;
    // Implement water treatment logic here
}

// Distribute water
void WaterPlant::distribureWater() {
    std::cout << "Water distributed from WaterPlant " << getPlantDetails() << "." << std::endl;
    // Implement water distribution logic here
}

// Change purification level
void WaterPlant::changePurificationLevel(std::string level) {
    purificationLevel = level;
    std::cout << "Purification level changed to " << purificationLevel << " at WaterPlant " << getPlantDetails() << "." << std::endl;
}

// Get the current water state
WaterPlantState* WaterPlant::getWaterState() {
    return dynamic_cast<WaterPlantState*>(getState());
}

// Start the plant by transitioning to the Running state
void WaterPlant::startPlant() {
    std::cout << "Starting WaterPlant: " << getPlantDetails() << std::endl;
    setState(new WaterPlantRunningState());
    notifyManagers();
}

// Stop the plant by transitioning to the Shutdown state
void WaterPlant::stopPlant() {
    std::cout << "Stopping WaterPlant: " << getPlantDetails() << std::endl;
    // Implement state transition to Shutdown
    // setState(new WaterPlantShutdownState()); // Uncomment if Shutdown state exists
    notifyManagers();
}

// Perform maintenance by transitioning to the Maintenance state
void WaterPlant::performMaintenance() {
    std::cout << "Performing maintenance on WaterPlant " << getPlantDetails() << "." << std::endl;
    // Implement state transition to Maintenance
    // setState(new WaterPlantMaintenanceState()); // Uncomment if Maintenance state exists
    notifyManagers();
}

// Start plant operations
void WaterPlant::startOperation() {
    std::cout << "WaterPlant " << getPlantDetails() << " has started operations." << std::endl;
    startWaterTreatment();
}

// Stop plant operations
void WaterPlant::stopOperation() {
    std::cout << "WaterPlant " << getPlantDetails() << " has stopped operations." << std::endl;
}

// Perform inspection, which triggers maintenance
void WaterPlant::performInspection() {
    std::cout << "Performing inspection on WaterPlant " << getPlantDetails() << "." << std::endl;
    performMaintenance();
}

// Get plant details
std::string WaterPlant::getPlantDetails() const {
    return "WaterPlant - Name: " + getName() + ", Location: " + getLocation() + ", Capacity: " + std::to_string(getCapacity());
}

// Get building details (same as plant details)
std::string WaterPlant::getBuildingDetails() const {
    return getPlantDetails();
}
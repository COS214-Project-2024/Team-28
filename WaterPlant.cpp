// #include "WaterPlant.h"
// #include <iostream>
// #include <string>
// #include "WaterPlantState.h"
// #include "WaterPlantRunningState.h"

// WaterPlant::WaterPlant(const std::string &name, const std::string &loc, int cap) 
//    : Plant(name, loc, cap), purificationLevel("Low"), NumberofLitres(0)
// {
//     setState(new WaterPlantRunningState());
// }

// WaterPlant::~WaterPlant()

// {
// }

// void WaterPlant::startWaterTreatment()
// {
//     std::cout << "Water treatment started" << std::endl;
// }

// void WaterPlant::distribureWater()
// {
//     std::cout << "Water distributed" << std::endl;
// }

// void WaterPlant::changePurificationLevel(std::string level)
// {
//     purificationLevel = level;
// }

// WaterPlantState *WaterPlant::getWaterState()
// {
//     return new WaterPlantState();
// }

// void WaterPlant::startPlant()
// {
//     std::cout << "Water Plant started" << std::endl;
// }

// void WaterPlant::stopPlant()
// {
//     std::cout << "Water Plant stopped" << std::endl;
// }

// void WaterPlant::performMaintenance()
// {
//     std::cout << "Water Plant maintenance performed" << std::endl;
// }

// std::string WaterPlant::getPlantDetails() const
// {
//     return "Water Plant";
// }

// void WaterPlant::startOperation()
// {
//     std::cout << "Water Plant operation started" << std::endl;
//     this->startPlant();
// }

// void WaterPlant::stopOperation()
// {
//     std::cout << "Water Plant operation stopped" << std::endl;
//     this->stopPlant();
// }

// void WaterPlant::performInspection()
// {
//     std::cout << "Water Plant inspection performed" << std::endl;
// }

// std::string WaterPlant::getBuildingDetails() const
// {
//     return "Water Plant";
// }

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

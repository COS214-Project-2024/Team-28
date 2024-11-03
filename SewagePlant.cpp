// SewagePlant.cpp
#include "SewagePlant.h"
#include "SewagePlantOperationalState.h"
#include "SewagePlantShutdownState.h"
#include "SewagePlantMaintenanceState.h"
#include "SewagePlantFailureState.h"
#include <iostream>

// Constructor Implementation
SewagePlant::SewagePlant(const std::string &name, const std::string &loc, int cap)
    : Plant(name, loc, cap), treatmentCapacity(cap), treatedVolume(0)
{
    // Initialize the plant state to Operational
    setState(new SewagePlantOperationalState());
    std::cout << "SewagePlant " << getPlantDetails() << " constructed and is now operational." << std::endl;
}

// Destructor Implementation
SewagePlant::~SewagePlant()
{
    // Assuming Plant class handles the deletion of the current state
    // If not, uncomment the following lines to delete the state
    // if (currentState) {
    //     delete currentState;
    //     currentState = nullptr;
    // }
}

// Start the plant by transitioning to the Operational state
void SewagePlant::startPlant()
{
    startOperation();
}

// Stop the plant by transitioning to the Shutdown state
void SewagePlant::stopPlant()
{
    stopOperation();
}

// Perform maintenance by transitioning to the Maintenance state
void SewagePlant::performMaintenance()
{
    std::cout << "Performing maintenance on SewagePlant " << getPlantDetails() << "." << std::endl;
    setState(new SewagePlantMaintenanceState());
}

// Start plant operations
void SewagePlant::startOperation()
{
    if (getState()->getStateName() != "Operating") {
        setState(new SewagePlantOperationalState());
        notifyManagers();
        std::cout << "SewagePlant " << getPlantDetails() << " has started operations." << std::endl;
    } else {
        std::cout << "SewagePlant " << getPlantDetails() << " is already operating." << std::endl;
    }
}

// Stop plant operations
void SewagePlant::stopOperation()
{
    if (getState()->getStateName() != "Shutdown") {
        setState(new SewagePlantShutdownState());
        notifyManagers();
        std::cout << "SewagePlant " << getPlantDetails() << " has been shut down." << std::endl;
    } else {
        std::cout << "SewagePlant " << getPlantDetails() << " is already shut down." << std::endl;
    }
}

// Perform inspection, which triggers maintenance
void SewagePlant::performInspection()
{
    std::cout << "Inspecting SewagePlant " << getPlantDetails() << "." << std::endl;
    performMaintenance();
}

// Get plant details
std::string SewagePlant::getPlantDetails() const
{
    return "SewagePlant - Name: " + getName() + ", Location: " + getLocation() + ", Capacity: " + std::to_string(treatmentCapacity);
}

// Get building details (same as plant details)
std::string SewagePlant::getBuildingDetails() const
{
    return getPlantDetails();
}

// Start sewage treatment process
void SewagePlant::startSewageTreatment()
{
    std::cout << "Sewage treatment started at SewagePlant " << getPlantDetails() << "." << std::endl;
    // Implement sewage treatment logic here, such as increasing treatedVolume
    treatedVolume += 100; // Example increment
    std::cout << "Treated volume increased by 100 units. Total treated volume: " 
              << treatedVolume << " units." << std::endl;
}

// Increase the plant's capacity
void SewagePlant::increaseCapacity(int newCapacity)
{
    treatmentCapacity += newCapacity;
    std::cout << "Increased capacity of SewagePlant " << getPlantDetails() 
              << " by " << newCapacity << " units. New capacity: " 
              << treatmentCapacity << std::endl;
}

// Get the current sewage state
SewagePlantState* SewagePlant::getSewageState()
{
    return dynamic_cast<SewagePlantState*>(getState());
}

// WastePlantObserver.cpp
#include "WastePlantObserver.h"
#include "Plant.h"        // To interact with Plant objects
#include "PlantState.h"   // To interact with PlantState objects
#include <algorithm>      // For std::find
#include <iostream>

// Override: Called when a plant's state changes
void WastePlantObserver::update(Plant* plant, PlantState* state) {
    std::cout << "Observer notified: " << plant->getPlantDetails() << std::endl;

    // Retrieve the new state name
    std::string stateName = state->getStateName();

    // Handle state changes accordingly
    if (stateName == "Shutdown") {
        initiateFaultHandling("Shutdown");
    }
    else if (stateName == "PartialState") {
        performRoutineMaintenance(plant);
    }
    else if (stateName == "Operating") {
        restorePlantOperations();
    }

    // Additional logic can be added here (e.g., logging, tracking faults)
}

// Override: Initiates fault handling procedures
void WastePlantObserver::initiateFaultHandling(const std::string& faultType) {
    if (faultActive) {
        std::cout << "Fault handling already active for: " << faultType << std::endl;
        return;
    }

    std::cout << "Initiating fault handling for: " << faultType << std::endl;
    faultActive = true;

    // Implement fault handling logic (e.g., dispatch maintenance crew)
    std::cout << "Dispatching maintenance crew to handle the fault." << std::endl;

    // After handling, attempt to restore operations
    restorePlantOperations();
}

// Override: Restores plant operations after a fault has been handled
void WastePlantObserver::restorePlantOperations() {
    std::cout << "Restoring plant operations." << std::endl;

    // Iterate through all managed plants
    for (auto plant : plants) {
        if (plant->getState()->getStateName() != "Operating") {
            plant->startPlant(); // Transition to Operating state
            // Notify stakeholders
            std::cout << "Notifying citizens: " << plant->getPlantDetails()
                      << " has resumed operations." << std::endl;
        }
    }
    faultActive = false;
}

// Override: Performs routine maintenance on a specific plant
void WastePlantObserver::performRoutineMaintenance(Plant* plant) {
    if (maintenanceInProgress) {
        std::cout << "Maintenance already in progress for " << plant->getPlantDetails() << std::endl;
        return; // Prevent re-entrant maintenance
    }

    maintenanceInProgress = true;

    std::cout << "Performing routine maintenance on " << plant->getPlantDetails() << std::endl;
    
    // **Removed the recursive call to performMaintenance**
    // plant->performMaintenance(); // This causes the loop

    // Simulate maintenance tasks here (e.g., system checks, repairs)
    std::cout << "Inspecting systems and performing necessary repairs." << std::endl;
    // ... (additional maintenance logic)

    std::cout << "Maintenance completed for: " << plant->getPlantDetails() << std::endl;

    // After maintenance, transition back to Operating to prevent infinite loops
    plant->startPlant();
    std::cout << "Plant " << plant->getPlantDetails() << " has resumed operations after maintenance." << std::endl;

    maintenanceInProgress = false;
}

// Override: Changes the state of a specific plant
void WastePlantObserver::changeState(Plant* plant, const std::string& newState) {
    if (newState == "Operating") {
        plant->startPlant();
    }
    else if (newState == "PartialState") {
        plant->performMaintenance();
    }
    else if (newState == "Shutdown") {
        plant->stopPlant();
    }
    // Additional state transitions can be handled here
}

// Override: Reports the current status of the observer and managed plants
void WastePlantObserver::reportStatus() const {
    std::cout << "Reporting status of WastePlantObserver: " << name << std::endl;
    std::cout << "----- Waste Plants Manager Status Report -----" << std::endl;
    std::cout << "Manager Name: " << name << std::endl;
    std::cout << "Number of Managed Plants: " << plants.size() << std::endl;

    // Iterate through all managed plants and report their details
    for (auto plant : plants) {
        std::cout << "  - " << plant->getPlantDetails() << std::endl;
    }

    std::cout << "Fault Active: " << (faultActive ? "Yes" : "No") << std::endl;
    std::cout << "Maintenance In Progress: " << (maintenanceInProgress ? "Yes" : "No") << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

// Override: Allocates necessary resources for managing waste plants
void WastePlantObserver::allocateResources() {
    std::cout << "Allocating resources for WastePlantObserver: " << name << std::endl;
    // Implement resource allocation logic here (e.g., budgeting, staffing)
}

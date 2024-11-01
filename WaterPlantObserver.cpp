// WaterPlantObserver.cpp
#include "WaterPlantObserver.h"
#include "Plant.h"       
#include "PlantState.h"   
#include <algorithm>      
#include <iostream>


void WaterPlantObserver::update(Plant* plant, PlantState* state) {
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
void WaterPlantObserver::initiateFaultHandling(const std::string& faultType) {
    std::cout << "Initiating fault handling for: " << faultType << std::endl;
    faultActive = true;

    // Implement fault handling logic (e.g., dispatch maintenance crew)
    std::cout << "Dispatching maintenance crew to handle the fault." << std::endl;

    // After handling, attempt to restore operations
    restorePlantOperations();
}

// Override: Restores plant operations after a fault has been handled
void WaterPlantObserver::restorePlantOperations() {
    std::cout << "Restoring plant operations." << std::endl;

    // Iterate through all managed plants
    for (auto plant : plants) {
        if (plant->getState()->getStateName() != "Operating") {
            plant->startPlant(); // Transition to Operating state
            // Notify citizens or other stakeholders
            std::cout << "Notifying citizens: " << plant->getPlantDetails()
                      << " has resumed operations." << std::endl;
        }
    }
    faultActive = false;
}

// Override: Performs routine maintenance on a specific plant
void WaterPlantObserver::performRoutineMaintenance(Plant* plant) {
    std::cout << "Performing routine maintenance on " << plant->getPlantDetails() << std::endl;
    plant->performMaintenance(); // Transition to PartialState

    std::cout << "Maintenance completed for: " << plant->getPlantDetails() << std::endl;

    // After maintenance, transition back to Operating to prevent infinite loops
    plant->startPlant();
    std::cout << "Plant " << plant->getPlantDetails() << " has resumed operations after maintenance." << std::endl;
}

// Override: Changes the state of a specific plant
void WaterPlantObserver::changeState(Plant* plant, const std::string& newState) {
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
void WaterPlantObserver::reportStatus() const {
    std::cout << "Reporting status of WaterPlantObserver: " << name << std::endl;
    std::cout << "----- Water Plants Manager Status Report -----" << std::endl;
    std::cout << "Manager Name: " << name << std::endl;
    std::cout << "Number of Managed Plants: " << plants.size() << std::endl;

    // Iterate through all managed plants and report their details
    for (auto plant : plants) {
        std::cout << "  - " << plant->getPlantDetails() << std::endl;
    }

    std::cout << "Fault Active: " << (faultActive ? "Yes" : "No") << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

// Override: Allocates necessary resources for managing water plants
void WaterPlantObserver::allocateResources() {
    std::cout << "Allocating resources for WaterPlantObserver: " << name << std::endl;
    // Implement resource allocation logic here (e.g., budgeting, staffing)
}

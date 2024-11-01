#include "PowerPlantObserver.h"
#include "PlantState.h" // Ensure full definition of PlantState
#include <algorithm>    // For std::find
#include <iostream>
#include <thread>       // Include for std::this_thread
#include <chrono>       // Include for std::chrono

void PowerPlantObserver::update(Plant* plant, PlantState* state) {
    std::cout << "Observer notified: " << plant->getPlantDetails() << std::endl;

    // Detect state change and handle accordingly
    std::string stateName = state->getStateName();

    if (stateName == "Shutdown") {
        initiateFaultHandling("Shutdown");
    } else if (stateName == "PartialState") {
        performRoutineMaintenance(plant);
    } else if (stateName == "Operating") {
        restorePlantOperations();
    }
}

void PowerPlantObserver::initiateFaultHandling(const std::string& faultType) {
    std::cout << "Initiating fault handling for: " << faultType << std::endl;
    faultActive = true;

    // Simulate time delay for fault handling
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Dispatching maintenance crew to handle the fault." << std::endl;
    restorePlantOperations();
}

void PowerPlantObserver::restorePlantOperations() {
    std::cout << "Restoring plant operations." << std::endl;
    for (auto plant : plants) {
        if (plant->getState()->getStateName() != "Operating") {
            plant->startPlant();
            std::cout << "Notifying citizens: " << plant->getPlantDetails() 
                      << " has resumed operations." << std::endl;
        }
    }
    faultActive = false;
}

void PowerPlantObserver::performRoutineMaintenance(Plant* plant) {
    std::cout << "Performing routine maintenance on " << plant->getPlantDetails() << std::endl;
    
    // Simulate time delay for maintenance
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    plant->performMaintenance();
    std::cout << "Maintenance completed for: " << plant->getPlantDetails() << std::endl;
    plant->startPlant();
    std::cout << "Plant " << plant->getPlantDetails() << " has resumed operations after maintenance." << std::endl;
}

void PowerPlantObserver::changeState(Plant* plant, const std::string& newState) {
    if (newState == "Operating") {
        plant->startPlant();
    } else if (newState == "PartialState") {
        plant->performMaintenance();
    } else if (newState == "Shutdown") {
        plant->stopPlant();
    }
}

void PowerPlantObserver::reportStatus() const {
    std::cout << "Reporting status of PowerPlantObserver: " << name << std::endl;
    std::cout << "----- Power Plants Manager Status Report -----" << std::endl;
    std::cout << "Manager Name: " << name << std::endl;
    std::cout << "Number of Managed Plants: " << plants.size() << std::endl;
    for (auto plant : plants) {
        std::cout << "  - " << plant->getPlantDetails() << std::endl;
    }
    std::cout << "Fault Active: " << (faultActive ? "Yes" : "No") << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

void PowerPlantObserver::allocateResources() {
    std::cout << "Allocating resources for PowerPlantObserver: " << name << std::endl;
}

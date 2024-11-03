// SewagePlantObserver.cpp
#include "SewagePlantObserver.h"
#include "Plant.h" // Added to get full Plant definition
#include "SewagePlant.h" // If needed for getPlantDetails()
#include "PlantState.h"      
#include <algorithm>              // For std::find
#include <iostream>
#include <thread>                 // For std::this_thread
#include <chrono>                 // For std::chrono

// Removed destructor implementation since it's defined inline in header

// update Method Implementation
void SewagePlantObserver::update(Plant* plant, PlantState* state) {
    std::cout << "Observer notified: " << plant->getPlantDetails() << std::endl;

    std::string stateName = state->getStateName();

    if (stateName == "Shutdown") {
        initiateFaultHandling("Blockage");
    } else if (stateName == "Failure") {

         initiateFaultHandling("SewageFailure");
    } else if (stateName == "Operating") {

        restorePlantOperations();
    }

}

// initiateFaultHandling Method Implementation
void SewagePlantObserver::initiateFaultHandling(const std::string& faultType) {
    std::cout << "Initiating fault handling for: " << faultType << std::endl;
    faultActive = true;

    // Pass the handling to the fault handler chain
    if (blockageHandlerChain) {
        blockageHandlerChain->handleRequest(this, faultType);
    }
}

// restorePlantOperations Method Implementation
void SewagePlantObserver::restorePlantOperations() {
    std::cout << "Restoring plant operations." << std::endl;
    for (auto plant : plants) {
        if (plant->getState()->getStateName() != "Operating") {
            plant->startPlant();
            // Notify citizens
            std::cout << "Notifying citizens: " << plant->getPlantDetails() 
                      << " has resumed operations." << std::endl;
        }
    }
    faultActive = false;
    maintenanceInProgress = false;
}

// performRoutineMaintenance Method Implementation
void SewagePlantObserver::performRoutineMaintenance(Plant* plant) {
    if (maintenanceInProgress) {
        std::cout << "Maintenance already in progress for " << plant->getPlantDetails() << std::endl;
        return;
    }

    std::cout << "Performing routine maintenance on " << plant->getPlantDetails() << std::endl;
    maintenanceInProgress = true;

    // Simulate time delay for maintenance
    std::this_thread::sleep_for(std::chrono::seconds(2));

    plant->performMaintenance();
    std::cout << "Maintenance completed for: " << plant->getPlantDetails() << std::endl;

    // After maintenance, transition back to Operating to prevent infinite loop
    plant->startPlant();
    std::cout << "Plant " << plant->getPlantDetails() << " has resumed operations after maintenance." << std::endl;

    maintenanceInProgress = false;
}
// Add this to SewagePlantObserver.cpp
void SewagePlantObserver::handleSewageBlockage(const std::string& faultType) {
    std::cout << "SewagePlantObserver: Handling sewage blockage - " << faultType << std::endl;
    if (blockageHandlerChain) {
        blockageHandlerChain->handleRequest(this, faultType);
    }
    // After handling blockage, check if we need to restore operations
    if (faultActive) {
        restorePlantOperations();
        faultActive = false;
    }
}
// changeState Method Implementation
void SewagePlantObserver::changeState(Plant* plant, const std::string& newState) {
    if (newState == "Operating") {
        plant->startPlant();
    } else if (newState == "Failure") {
        // Handle failure state
        // For example, set plant to failure state
        // plant->setState(new SewagePlantFailureState(true));
    } else if (newState == "Shutdown") {
        plant->stopPlant();
    }
}

// reportStatus Method Implementation
void SewagePlantObserver::reportStatus() const {
    std::cout << "Reporting status of SewagePlantObserver: " << name << std::endl;
    std::cout << "----- Sewage Plants Manager Status Report -----" << std::endl;
    std::cout << "Manager Name: " << name << std::endl;
    std::cout << "Number of Managed Plants: " << plants.size() << std::endl;
    for (auto plant : plants) {
        std::cout << "  - " << plant->getPlantDetails() << std::endl;
    }
    std::cout << "Fault Active: " << (faultActive ? "Yes" : "No") << std::endl;
    std::cout << "Maintenance In Progress: " << (maintenanceInProgress ? "Yes" : "No") << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

// allocateResources Method Implementation
void SewagePlantObserver::allocateResources() {
    std::cout << "Allocating resources for SewagePlantObserver: " << name << std::endl;
    // Implement resource allocation logic here
}

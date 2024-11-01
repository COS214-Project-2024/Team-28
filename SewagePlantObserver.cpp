// SewagePlantObserver.cpp
#include "SewagePlantObserver.h"
#include "PlantState.h" // Ensure full definition of PlantState
#include <algorithm>    // For std::find

void SewagePlantObserver::update(Plant* plant, PlantState* state) {
    std::cout << "Observer notified: " << plant->getPlantDetails() << std::endl;

    // Detect state change and handle accordingly
    std::string stateName = state->getStateName();

    if (stateName == "Shutdown") {
        initiateFaultHandling("Shutdown");
    } else if (stateName == "PartialState") {
        performRoutineMaintenance(plant); // Pass the specific plant
    } else if (stateName == "Operating") {
        restorePlantOperations();
    }

    // Example: Track faults (this could be more elaborate)
    // You might maintain a fault count or log here
}

void SewagePlantObserver::initiateFaultHandling(const std::string& faultType) {
    std::cout << "Initiating fault handling for: " << faultType << std::endl;
    faultActive = true;

    // Implement fault handling logic, e.g., dispatch maintenance crew

    // Example: Dispatch maintenance crew
    std::cout << "Dispatching maintenance crew to handle the fault." << std::endl;

    // After handling, restore operations
    restorePlantOperations();
}

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
}

void SewagePlantObserver::performRoutineMaintenance(Plant* plant) {
    std::cout << "Performing routine maintenance on " << plant->getPlantDetails() << std::endl;
    plant->performMaintenance();
    std::cout << "Maintenance completed for: " << plant->getPlantDetails() << std::endl;

    // After maintenance, transition back to Operating to prevent infinite loop
    plant->startPlant();
    std::cout << "Plant " << plant->getPlantDetails() << " has resumed operations after maintenance." << std::endl;
}

void SewagePlantObserver::changeState(Plant* plant, const std::string& newState) {
    if (newState == "Operating") {
        plant->startPlant();
    } else if (newState == "PartialState") {
        plant->performMaintenance();
    } else if (newState == "Shutdown") {
        plant->stopPlant();
    }
}

void SewagePlantObserver::reportStatus() const {
    std::cout << "Reporting status of SewagePlantObserver: " << name << std::endl;
    // Implement reporting logic here
    std::cout << "----- Sewage Plants Manager Status Report -----" << std::endl;
    std::cout << "Manager Name: " << name << std::endl;
    std::cout << "Number of Managed Plants: " << plants.size() << std::endl;
    for (auto plant : plants) {
        std::cout << "  - " << plant->getPlantDetails() << std::endl;
    }
    std::cout << "Fault Active: " << (faultActive ? "Yes" : "No") << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

void SewagePlantObserver::allocateResources() {
    std::cout << "Allocating resources for SewagePlantObserver: " << name << std::endl;
    // Implement resource allocation logic here
}

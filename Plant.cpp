// Plant.cpp
#include "Plant.h"
#include "PlantsManager.h"
#include "PlantState.h"
#include <iostream>
#include <algorithm>


Plant::~Plant() {
    delete currentStatus;
    std::cout << "Plant destructed." << std::endl;
}

// Attach a manager to the plant
void Plant::attachManager(PlantsManager* manager) {
    if (std::find(managers.begin(), managers.end(), manager) == managers.end()) {
        managers.push_back(manager);
        std::cout << "Manager " << manager->getName() << " attached to plant " << getPlantDetails() << std::endl;
    }
}

// Detach a manager from the plant
void Plant::detachManager(PlantsManager* manager) {
    managers.erase(std::remove(managers.begin(), managers.end(), manager), managers.end());
    std::cout << "Manager " << manager->getName() << " detached from plant " << getPlantDetails() << std::endl;
}

// Notify all attached managers of a state change
void Plant::notifyManagers() {
    for (auto manager : managers) {
        manager->update(this, currentStatus);
    }
}

// Set the plant's state and notify managers
void Plant::setState(PlantState* newState) {
    delete currentStatus;
    currentStatus = newState;
    std::cout << "Plant " << getPlantDetails() << " changed state to " << newState->getStateName() << std::endl;
    notifyManagers();
}

// Get the plant's current state
PlantState* Plant::getState() const {
    return currentStatus;
}

// Set the plant's demand with validation
// void Plant::setDemand(int newDemand) {
//     if (newDemand < 0) {
//         currentDemand = 0;
//     } else {
//         currentDemand = newDemand;
//     }
//     std::cout << "Demand for plant " << getPlantDetails() << " set to " << currentDemand << std::endl;
//     checkAndHandleDemand();
// }

// Check if demand exceeds capacity and handle faults
void Plant::checkAndHandleDemand() {
    if (currentDemand > capacity) {
        std::cout << "Demand exceeds capacity for " << getPlantDetails() << ". Triggering fault." << std::endl;
        // handleFault();
    }
}

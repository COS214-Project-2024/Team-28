// PlantStateHandler.cpp
#include "PlantStateHandler.h"
#include "PlantsManager.h"
#include <iostream>

// Constructor
PlantStateHandler::PlantStateHandler() : FaultHandler() {}

// Destructor
PlantStateHandler::~PlantStateHandler() {
    // Any necessary cleanup can be done here
}

// Override: Handle specific plant state faults
void PlantStateHandler::handleRequest(PlantsManager* manager, const std::string& faultType) {
    // Example: Handle "MaintenanceRequired" fault type
    if (faultType == "MaintenanceRequired") {
        std::cout << "[PlantStateHandler] Handling fault: " << faultType 
                  << " for manager: " << manager->getName() << std::endl;
        // Implement maintenance procedures
        // This might involve calling specific methods on the manager
        // For example:
        // manager->performRoutineMaintenance();
    }
    else if (nextHandler) {
        // Pass the fault to the next handler in the chain
        nextHandler->handleRequest(manager, faultType);
    }
    else {
        // No handler available for this fault
        std::cout << "[PlantStateHandler] No handler available for fault: " << faultType << std::endl;
    }
}

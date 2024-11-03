// PowerHandler.cpp
#include "PowerHandler.h"
#include "PowerPlantObserver.h"
#include <iostream>

// Default constructor
PowerHandler::PowerHandler() : FaultHandler() {}

// Destructor implementation
PowerHandler::~PowerHandler() {
    // Any necessary cleanup can be done here
    // Currently empty
}

void PowerHandler::handleRequest(PlantsManager* manager, const std::string& faultType) {
    // Attempt to cast the manager to PowerPlantObserver
    PowerPlantObserver* powerObserver = dynamic_cast<PowerPlantObserver*>(manager);
    if (powerObserver) {
        std::cout << "[PowerHandler] Handling fault: " << faultType 
                  << " for manager: " << manager->getName() << std::endl;
        // Delegate the fault handling to the PowerPlantObserver
        powerObserver->handlePowerFault(faultType);
    } else if (nextHandler) {
        // Pass the fault to the next handler in the chain
        nextHandler->handleRequest(manager, faultType);
    } else {
        // No handler available for this fault
        std::cout << "[PowerHandler] No handler available for fault: " << faultType << std::endl;
    }
}

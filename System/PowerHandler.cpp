// PowerHandler.cpp
#include "PowerHandler.h"
#include "PowerPlantObserver.h"
#include <iostream>

// Default constructor
PowerHandler::PowerHandler() : PlantStateHandler() {}

// Destructor implementation
PowerHandler::~PowerHandler() {
    // Any necessary cleanup can be done here
    // Currently empty
}

void PowerHandler::handleRequest(PlantsManager* manager, const std::string& faultType) {
  std::cout << "Fault: \"" << faultType << "\" passed by manager \"" 
              << manager->getName() << "\" has been fixed by handler \"PowerHandler\"." 
              << std::endl;

}

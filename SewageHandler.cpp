#include "SewageHandler.h"
#include <iostream>

SewageHandler::SewageHandler() {
    sewagePlantName = "SewagePlant1";
}

SewageHandler::~SewageHandler() {}

void SewageHandler::restorePlantOperations() {
    std::cout << "Restoring operations for " << sewagePlantName << std::endl;
}

void SewageHandler::performRoutineMaintenance() {
    std::cout << "Performing routine maintenance for " << sewagePlantName << std::endl;
}

void SewageHandler::changeState(string newState) {
    std::cout << "Changing state to " << newState << " for " << sewagePlantName << std::endl;
}


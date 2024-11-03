#include "WasteHandler.h"
#include <iostream>

WasteHandler::WasteHandler() {
    stationPointer = new WastePlant("WastePlant1", "Downtown", 1000);
}

WasteHandler::~WasteHandler() {
    delete stationPointer;
}

void WasteHandler::restorePlantOperations() {
    std::cout << "Restoring operations for WastePlant1" << std::endl;
}

void WasteHandler::performRoutineMaintenance() {
    std::cout << "Performing routine maintenance for WastePlant1" << std::endl;
}

void WasteHandler::changeState(string newState) {
    std::cout << "Changing state to " << newState << " for WastePlant1" << std::endl;
}


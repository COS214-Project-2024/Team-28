// SewagePlantMaintenanceState.cpp
#include "SewagePlantMaintenanceState.h"
#include "SewagePlantOperationalState.h"
#include "SewagePlant.h"
#include <iostream>
#include <thread>
#include <chrono>

void SewagePlantMaintenanceState::handleState(Plant* plant) {
    SewagePlant* sewagePlant = dynamic_cast<SewagePlant*>(plant);
    if (sewagePlant) {
        std::cout << sewagePlant->getPlantDetails() << " is under maintenance." << std::endl;
        // Simulate maintenance duration
        std::cout << "Maintenance in progress..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate maintenance time
        std::cout << "Maintenance completed. Transitioning back to Operating state." << std::endl;

        // Transition back to operational state
        SewagePlantState* operationalState = new SewagePlantOperationalState();
        plant->setState(operationalState);
    } else {
        std::cerr << "Error: Plant is not a SewagePlant." << std::endl;
    }
}

std::string SewagePlantMaintenanceState::getStateName() {
    return "Maintenance";
}

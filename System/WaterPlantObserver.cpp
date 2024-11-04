#include "WaterPlantObserver.h"
#include <iostream>

WaterPlantObserver::WaterPlantObserver(const std::string& managerName)
    : PlantsManager(managerName) {}

WaterPlantObserver::~WaterPlantObserver() {}

void WaterPlantObserver::update(Plant* plant, PlantState* state) {
    std::cout << "Observer notified: " << plant->getPlantDetails() << std::endl;
}

void WaterPlantObserver::initiateFaultHandling(const std::string& faultType) {
    std::cout << "Initiating fault handling for: " << faultType << std::endl;
}

void WaterPlantObserver::restorePlantOperations() {
    std::cout << "Restoring plant operations." << std::endl;
}

void WaterPlantObserver::performRoutineMaintenance(Plant* plant) {
    std::cout << "Performing routine maintenance on " << plant->getPlantDetails() << std::endl;
}

void WaterPlantObserver::changeState(Plant* plant, const std::string& newState) {
    std::cout << "Changing state of " << plant->getPlantDetails() << " to " << newState << std::endl;
}

void WaterPlantObserver::reportStatus() const {
    std::cout << "Reporting status of WaterPlantObserver: " << getName() << std::endl;
}

void WaterPlantObserver::allocateResources() {
    std::cout << "Allocating resources." << std::endl;
}
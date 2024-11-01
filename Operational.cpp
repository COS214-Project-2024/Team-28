// Operational.cpp
#include "Operational.h"
#include "Plant.h"

void Operational::handleState(Plant* plant) {
    std::cout << plant->getPlantDetails() << " is operating normally." << std::endl;
}

std::string Operational::getStateName() const {
    return "Operating";
}
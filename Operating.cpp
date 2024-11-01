// Operating.cpp
#include "Operating.h"
#include "Plant.h"

void Operating::handleState(Plant* plant) {
    std::cout << plant->getPlantDetails() << " is operating normally." << std::endl;
}

std::string Operating::getStateName() const {
    return "Operating";
}
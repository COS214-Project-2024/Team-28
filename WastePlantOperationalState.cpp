// Operating.cpp
#include "WastePlantOperationalState.h"
#include "Plant.h"
#include <iostream>
using namespace std;

void WastePlantOperationalState::handleState(Plant* plant) {
    std::cout << plant->getPlantDetails() << " is operating normally." << std::endl;
}

std::string WastePlantOperationalState::getStateName(){
    return "Operating";
}
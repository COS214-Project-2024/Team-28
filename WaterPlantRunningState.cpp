#include "WaterPlantRunningState.h"
#include <iostream>
#include "WaterPlant.h"  
#include <iostream>

WaterPlantRunningState::WaterPlantRunningState() {}

WaterPlantRunningState::~WaterPlantRunningState() {}


void WaterPlantRunningState::handleWaterState() {    
    std::cout << "Handling water state in running state." << std::endl;

}

void WaterPlantRunningState::handleState(Plant* plant) {
    WaterPlant* waterPlant = dynamic_cast<WaterPlant*>(plant);
    if (waterPlant) {
        std::cout << waterPlant->getPlantDetails() << " is running normally." << std::endl;
           }
}
std::string WaterPlantRunningState::getStateName() {
    return "Running";
}
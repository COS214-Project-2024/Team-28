
#include "WastePlantMaintenanceState.h"
#include "Plant.h"

void PartialState::handleState(Plant* plant) {
    std::cout << plant->getPlantDetails() << " is partially operational due to maintenance." << std::endl;
    // Additional logic for partial state can be added here
}

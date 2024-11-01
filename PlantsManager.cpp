// PlantsManager.cpp
#include "PlantsManager.h"
#include "Plant.h"        // Included to resolve incomplete type
#include "PlantState.h"   // Include if PlantState is used in this file
#include <algorithm>
#include <iostream>

// Attach a plant to the manager
void PlantsManager::attach(Plant* plant) {
    if (std::find(plants.begin(), plants.end(), plant) == plants.end()) {
        plants.push_back(plant);
        plant->attachManager(this);
        std::cout << "Plant " << plant->getPlantDetails() << " attached to manager " << getName() << std::endl;
    }
}

// Detach a plant from the manager
void PlantsManager::detach(Plant* plant) {
    plants.erase(std::remove(plants.begin(), plants.end(), plant), plants.end());
    plant->detachManager(this);
    std::cout << "Plant " << plant->getPlantDetails() << " detached from manager " << getName() << std::endl;
}

#include "HighPopulationStrategy.h"
#include "Government.h"
#include "ResidentialBuildingFactory.h"
#include <iostream>

void HighPopulationStrategy::executeStrategy(Government* government) {
    std::cout << "Executing High Population Strategy..." << std::endl;

    // Example logic to create a new building
    ResidentialBuildingFactory residentialFactory;
    ResidentialBuilding* newBuilding = residentialFactory.createHouse(); // Example: creating a new house with 5 residents
    if (newBuilding) {
        std::cout << "New building created at " " with " " residents." << std::endl;
    } else {
        std::cout << "Failed to create a new building." << std::endl;
    }
}
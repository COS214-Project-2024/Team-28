#include "Overload.h"
#include "Plant.h"

void Overload::handleState(Plant* plant) {
    std::cout << plant->getPlantDetails() << " is Overloaded." << std::endl;
    // Additional logic for operating state can be added here
}
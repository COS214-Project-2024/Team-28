// PowerPlantShutdownState 
#include "PowerPlantShutdownState .h"
#include "Plant.h"

void PowerPlantShutdownState ::handleState(Plant* plant) {
    std::cout << plant->getPlantDetails() << " is shut down." << std::endl;
    // Additional logic for shutdown state can be added here
}
  std::string PowerPlantShutdownState:: getStateName() 
   { return "Shutdown"; }
#include "WaterHandler.h"
#include "WaterPlantObserver.h"
#include <iostream>


WaterHandler::WaterHandler(): PlantStateHandler(){}

WaterHandler::~WaterHandler(){

}

void WaterHandler :: handleRequest(PlantsManager* manager, const std::string& faultType){
      std::cout << "Fault: \"" << faultType << "\" passed by manager \"" 
              << manager->getName() << "\" has been fixed by handler \"WaterHandler\"." 
              << std::endl;
}
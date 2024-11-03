#include "SewageHandler.h"
#include "SewagePlantObserver.h"
#include <iostream>

SewageHandler::SewageHandler() : PlantStateHandler()
{
}

SewageHandler::~SewageHandler() {}

void SewageHandler::handleRequest(PlantsManager *manager, const std::string &faultType)
{
    std::cout << "Fault: \"" << faultType << "\" passed by manager \""
              << manager->getName() << "\" has been fixed by handler \"SewageHandler\"."
              << std::endl;
}
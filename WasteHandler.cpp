#include "WasteHandler.h"
#include <iostream>

WasteHandler::WasteHandler() : PlantStateHandler() {}

WasteHandler::~WasteHandler()
{
}

void WasteHandler::handleRequest(PlantsManager *manager, const std::string &faultType)
{
    std::cout << "Fault: \"" << faultType << "\" passed by manager \""
              << manager->getName() << "\" has been fixed by handler \"WasteHandler\"."
              << std::endl;
}
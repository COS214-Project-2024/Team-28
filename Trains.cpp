#include "Trains.h"
#include <iostream>

Trains::Trains() : Services("Trains", 100) {}

void Trains::provideService() {
    std::cout << "Providing train services..." << std::endl;
}

void Trains::addTrain(const std::string& trainName) {
    trains.push_back(trainName);
    std::cout << "Adding train: " << trainName << std::endl;
}

void Trains::removeTrain(const std::string& trainName) {
    std::cout << "Removing train: " << trainName << std::endl;
}

void Trains::scheduleTrain(const std::string& routeName) {
    routes.push_back(routeName);
    std::cout << "Scheduling train for route: " << routeName << std::endl;
}

void Trains::announceDelay(int delayMinutes) {
    std::cout << "Announcing delay of " << delayMinutes << " minutes for trains." << std::endl;
}
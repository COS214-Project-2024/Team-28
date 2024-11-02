#include "PublicTransit.h"
#include <iostream>

PublicTransit::PublicTransit() : Services("PublicTransit", 100) {}

void PublicTransit::provideService() {
    std::cout << "Providing public transit services..." << std::endl;
}

void PublicTransit::addVehicle(const std::string& vehicleType) {
    vehicles.push_back(vehicleType);
    std::cout << "Adding " << vehicleType << " to public transit." << std::endl;
}

void PublicTransit::removeVehicle(const std::string& vehicleType) {
    std::cout << "Removing " << vehicleType << " from public transit." << std::endl;
}

void PublicTransit::announceDelay(int delayMinutes) {
    std::cout << "Announcing delay of " << delayMinutes << " minutes for public transit." << std::endl;
}
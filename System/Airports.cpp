#include "Airports.h"
#include <iostream>

Airports::Airports() : Services("Airports", 100) {}

void Airports::provideService() {
    std::cout << "Providing airport services..." << std::endl;
}

void Airports::addFlight(const std::string& flightName) {
    flights.push_back(flightName);
    std::cout << "Adding flight: " << flightName << std::endl;
}

void Airports::removeFlight(const std::string& flightName) {
    std::cout << "Removing flight: " << flightName << std::endl;
}

void Airports::scheduleFlightMaintenance() {
    std::cout << "Scheduling flight maintenance." << std::endl;
}
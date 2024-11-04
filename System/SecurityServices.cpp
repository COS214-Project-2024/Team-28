#include "SecurityServices.h"
#include <iostream>

SecurityServices::SecurityServices() : Services("Security", 100) {}

void SecurityServices::provideService() {
    std::cout << "Providing security services..." << std::endl;
}

void SecurityServices::respondToEmergency(const std::string& location) {
    std::cout << "Responding to emergency at: " << location << std::endl;
}

void SecurityServices::conductPatrol() {
    std::cout << "Conducting patrol..." << std::endl;
}
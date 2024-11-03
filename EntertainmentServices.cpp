#include "EntertainmentServices.h"
#include <iostream>

EntertainmentServices::EntertainmentServices() : Services("Entertainment", 100) {}

void EntertainmentServices::provideService() {
    std::cout << "Providing entertainment services..." << std::endl;
}

void EntertainmentServices::organizeEvent(const std::string& eventName) {
    events.push_back(eventName);
    std::cout << "Organizing event: " << eventName << std::endl;
}

void EntertainmentServices::cancelEvent(const std::string& eventName) {
    std::cout << "Canceling event: " << eventName << std::endl;
}
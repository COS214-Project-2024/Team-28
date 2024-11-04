#include "Services.h"
#include <iostream>

Services::Services(const std::string& serviceType, int capacity) : serviceType(serviceType), capacity(capacity) {}

void Services::scheduleService(const std::string& serviceTime) {
    std::cout << "Scheduling " << serviceType << " service at " << serviceTime << std::endl;
}

void Services::handleServiceRequest(const std::string& request) {
    std::cout << "Handling " << serviceType << " service request: " << request << std::endl;
}

void Services::acknowledgeBudgetAllocation(double amount) {
    std::cout << "Thanks City Manager for giving us " << serviceType << " R" << amount << std::endl;
}

void Services::acknowledgeServiceRequest() {
    std::cout << "Hi City Manager, " << serviceType << " Service has been granted as per your request" << std::endl;
}
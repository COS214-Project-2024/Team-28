#include "CityManager.h"
#include <iostream>

CityManager::CityManager() : healthBudget(1000000.0), educationBudget(1000000.0), entertainmentBudget(500000.0), securityBudget(1000000.0), transportationBudget(1000000.0) {
    services.push_back(new HealthServices());
    services.push_back(new EducationServices());
    services.push_back(new EntertainmentServices());
    services.push_back(new SecurityServices());
    services.push_back(new TransportationServices());
}

void CityManager::notifyCitizens(const std::string& message) {
    std::cout << "City Manager: " << message << std::endl;
}

void CityManager::manageServices() {
    for (auto service : services) {
        service->provideService();
    }
}

void CityManager::allocateBudget(const std::string& serviceType, double amount) {
    if (serviceType == "Health") {
        healthBudget += amount;
        services[0]->acknowledgeBudgetAllocation(amount);
    } else if (serviceType == "Education") {
        educationBudget += amount;
        services[1]->acknowledgeBudgetAllocation(amount);
    } else if (serviceType == "Entertainment") {
        entertainmentBudget += amount;
        services[2]->acknowledgeBudgetAllocation(amount);
    } else if (serviceType == "Security") {
        securityBudget += amount;
        services[3]->acknowledgeBudgetAllocation(amount);
    } else if (serviceType == "Transportation") {
        transportationBudget += amount;
        services[4]->acknowledgeBudgetAllocation(amount);
    }
}

void CityManager::requestService(const std::string& serviceType) {
    if (serviceType == "Health") {
        if (healthBudget > 0) {
            services[0]->provideService();
            healthBudget -= 10000.0; // Example cost per service request
            services[0]->acknowledgeServiceRequest();
        } else {
            std::cout << "Health service budget depleted. Request denied." << std::endl;
        }
    } else if (serviceType == "Education") {
        if (educationBudget > 0) {
            services[1]->provideService();
            educationBudget -= 10000.0; // Example cost per service request
            services[1]->acknowledgeServiceRequest();
        } else {
            std::cout << "Education service budget depleted. Request denied." << std::endl;
        }
    } else if (serviceType == "Entertainment") {
        if (entertainmentBudget > 0) {
            services[2]->provideService();
            entertainmentBudget -= 10000.0; // Example cost per service request
            services[2]->acknowledgeServiceRequest();
        } else {
            std::cout << "Entertainment service budget depleted. Request denied." << std::endl;
        }
    } else if (serviceType == "Security") {
        if (securityBudget > 0) {
            services[3]->provideService();
            securityBudget -= 10000.0; // Example cost per service request
            services[3]->acknowledgeServiceRequest();
        } else {
            std::cout << "Security service budget depleted. Request denied." << std::endl;
        }
    } else if (serviceType == "Transportation") {
        if (transportationBudget > 0) {
            services[4]->provideService();
            transportationBudget -= 10000.0; // Example cost per service request
            services[4]->acknowledgeServiceRequest();
        } else {
            std::cout << "Transportation service budget depleted. Request denied." << std::endl;
        }
    }
}

Services* CityManager::getService(const std::string& serviceType) {
    if (serviceType == "Health") {
        return services[0];
    } else if (serviceType == "Education") {
        return services[1];
    } else if (serviceType == "Entertainment") {
        return services[2];
    } else if (serviceType == "Security") {
        return services[3];
    } else if (serviceType == "Transportation") {
        return services[4];
    } else if (serviceType == "PublicTransit") {
        return dynamic_cast<TransportationServices*>(services[4])->getPublicTransit();
    } else if (serviceType == "Trains") {
        return dynamic_cast<TransportationServices*>(services[4])->getTrains();
    } else if (serviceType == "Airports") {
        return dynamic_cast<TransportationServices*>(services[4])->getAirports();
    } else if (serviceType == "Roads") {
        return dynamic_cast<TransportationServices*>(services[4])->getRoads();
    }
    return nullptr;
}
#ifndef CITYMANAGER_H
#define CITYMANAGER_H

#include <string>
#include <vector>
#include "Services.h"
#include "HealthServices.h"
#include "EducationServices.h"
#include "EntertainmentServices.h"
#include "SecurityServices.h"
#include "TransportationServices.h"
#include "PublicTransit.h"
#include "Trains.h"
#include "Airports.h"
#include "Roads.h"
#include "Citizen.h"

class CityManager {
public:
    CityManager();
    void notifyCitizens(const std::string& message);
    void manageServices();
    void allocateBudget(const std::string& serviceType, double amount);
    void requestService(const std::string& serviceType);
    Services* getService(const std::string& serviceType);
    void payLevies(const std::vector<Citizen>& citizens);

private:
    std::vector<Services*> services;
    double healthBudget;
    double educationBudget;
    double entertainmentBudget;
    double securityBudget;
    double transportationBudget;
};

#endif // CITYMANAGER_H
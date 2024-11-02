#ifndef TRANSPORTATIONSERVICES_H
#define TRANSPORTATIONSERVICES_H

#include "Services.h"
#include "PublicTransit.h"
#include "Trains.h"
#include "Airports.h"
#include "Roads.h"
#include <string>
#include <vector>

class TransportationServices : public Services {
public:
    TransportationServices();
    void provideService() override;
    void addRoute(const std::string& routeName);
    void removeRoute(const std::string& routeName);
    void scheduleMaintenance();
    void handleTraffic();
    void manageSubsystems();
    PublicTransit* getPublicTransit();
    Trains* getTrains();
    Airports* getAirports();
    Roads* getRoads();

private:
    PublicTransit publicTransit;
    Trains trains;
    Airports airports;
    Roads roads;
    std::vector<std::string> routes;
};

#endif // TRANSPORTATIONSERVICES_H
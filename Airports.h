#ifndef AIRPORTS_H
#define AIRPORTS_H

#include "Services.h"
#include <string>
#include <vector>

class Airports : public Services {
public:
    Airports();
    void provideService() override;
    void addFlight(const std::string& flightName);
    void removeFlight(const std::string& flightName);
    void scheduleFlightMaintenance();

private:
    std::vector<std::string> flights;
};

#endif // AIRPORTS_H
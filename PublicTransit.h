#ifndef PUBLICTRANSIT_H
#define PUBLICTRANSIT_H

#include "Services.h"
#include <string>
#include <vector>

class PublicTransit : public Services {
public:
    PublicTransit();
    void provideService() override;
    void addVehicle(const std::string& vehicleType);
    void removeVehicle(const std::string& vehicleType);
    void announceDelay(int delayMinutes);

private:
    std::vector<std::string> vehicles;
};

#endif // PUBLICTRANSIT_H
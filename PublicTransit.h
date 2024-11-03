#ifndef PUBLICTRANSIT_H
#define PUBLICTRANSIT_H

#include "Services.h"
#include <string>
#include <vector>

/**
 * @class PublicTransit
 * @brief Represents public transit services in the city.
 *
 * This class manages the public transit services, including vehicles,
 * delays, and service provision. It inherits from the Services class
 * and implements the provideService method.
 */
class PublicTransit : public Services {
public:
    /**
     * @brief Default constructor for PublicTransit.
     *
     * Initializes the public transit service and its internal vehicle list.
     */
    PublicTransit();

    /**
     * @brief Provides public transit service.
     * 
     * This method implements the service provision logic, which may include
     * announcing schedules or operating vehicles.
     */
    void provideService() override;

    /**
     * @brief Adds a vehicle to the public transit system.
     * 
     * @param vehicleType The type of vehicle to add (e.g., bus, tram).
     */
    void addVehicle(const std::string& vehicleType);

    /**
     * @brief Removes a vehicle from the public transit system.
     * 
     * @param vehicleType The type of vehicle to remove.
     */
    void removeVehicle(const std::string& vehicleType);

    /**
     * @brief Announces a delay in public transit.
     * 
     * @param delayMinutes The number of minutes of the delay.
     */
    void announceDelay(int delayMinutes);

private:
    std::vector<std::string> vehicles; ///< List of vehicles in the public transit system.
};

#endif // PUBLICTRANSIT_H

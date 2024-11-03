#ifndef AIRPORTS_H
#define AIRPORTS_H

#include "Services.h"
#include <string>
#include <vector>

/**
 * @class Airports
 * @brief A class representing airport services.
 *
 * This class is responsible for managing airport-related services,
 * including adding and removing flights and scheduling maintenance.
 */
class Airports : public Services {
public:
    /**
     * @brief Default constructor for the Airports class.
     */
    Airports();

    /**
     * @brief Provides airport services.
     *
     * This method overrides the provideService function from the Services class.
     */
    void provideService() override;

    /**
     * @brief Adds a flight to the airport.
     * @param flightName The name of the flight to be added.
     */
    void addFlight(const std::string& flightName);

    /**
     * @brief Removes a flight from the airport.
     * @param flightName The name of the flight to be removed.
     */
    void removeFlight(const std::string& flightName);

    /**
     * @brief Schedules maintenance for the flights.
     *
     * This method performs maintenance operations on all scheduled flights.
     */
    void scheduleFlightMaintenance();

private:
    std::vector<std::string> flights; /**< A vector containing the list of flights. */
};

#endif // AIRPORTS_H

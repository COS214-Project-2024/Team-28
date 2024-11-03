#ifndef TRANSPORTATIONSERVICES_H
#define TRANSPORTATIONSERVICES_H

#include "Services.h"
#include "PublicTransit.h"
#include "Trains.h"
#include "Airports.h"
#include "Roads.h"
#include <string>
#include <vector>

/**
 * @class TransportationServices
 * @brief A class that manages various transportation services.
 *
 * This class provides functionalities to manage public transit,
 * trains, airports, and roads, handling route management and maintenance.
 */
class TransportationServices : public Services {
public:
    /// Constructor for the TransportationServices class.
    TransportationServices();

    /**
     * @brief Provides the transportation service.
     *
     * This method implements the service provision logic for all
     * transportation subsystems.
     */
    void provideService() override;

    /**
     * @brief Adds a new route to the transportation system.
     *
     * @param routeName The name of the route to be added.
     */
    void addRoute(const std::string& routeName);

    /**
     * @brief Removes an existing route from the transportation system.
     *
     * @param routeName The name of the route to be removed.
     */
    void removeRoute(const std::string& routeName);

    /**
     * @brief Schedules maintenance for the transportation services.
     *
     * This method implements the maintenance scheduling logic.
     */
    void scheduleMaintenance();

    /**
     * @brief Handles traffic management within the transportation system.
     *
     * This method implements traffic regulation and control.
     */
    void handleTraffic();

    /**
     * @brief Manages the various transportation subsystems.
     *
     * This method oversees the operation and coordination of public transit,
     * trains, airports, and roads.
     */
    void manageSubsystems();

    /**
     * @brief Gets the public transit service.
     *
     * @return A pointer to the PublicTransit service.
     */
    PublicTransit* getPublicTransit();

    /**
     * @brief Gets the trains service.
     *
     * @return A pointer to the Trains service.
     */
    Trains* getTrains();

    /**
     * @brief Gets the airports service.
     *
     * @return A pointer to the Airports service.
     */
    Airports* getAirports();

    /**
     * @brief Gets the roads service.
     *
     * @return A pointer to the Roads service.
     */
    Roads* getRoads();

private:
    PublicTransit publicTransit; ///< The public transit subsystem.
    Trains trains;               ///< The trains subsystem.
    Airports airports;           ///< The airports subsystem.
    Roads roads;                 ///< The roads subsystem.
    std::vector<std::string> routes; ///< List of routes managed by the transportation service.
};

#endif // TRANSPORTATIONSERVICES_H

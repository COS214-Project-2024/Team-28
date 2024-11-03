#ifndef TRAINS_H
#define TRAINS_H

#include "Services.h"
#include <string>
#include <vector>

/**
 * @class Trains
 * @brief A class representing train services.
 *
 * This class provides functionalities to manage train services,
 * including adding and removing trains, scheduling routes, and handling delays.
 */
class Trains : public Services {
public:
    /// Constructor for the Trains class.
    Trains();

    /**
     * @brief Provides the train service.
     *
     * This method implements the service provision logic.
     */
    void provideService() override;

    /**
     * @brief Adds a train to the service.
     *
     * @param trainName The name of the train to be added.
     */
    void addTrain(const std::string& trainName);

    /**
     * @brief Removes a train from the service.
     *
     * @param trainName The name of the train to be removed.
     */
    void removeTrain(const std::string& trainName);

    /**
     * @brief Schedules a train for a specific route.
     *
     * @param routeName The name of the route to schedule the train on.
     */
    void scheduleTrain(const std::string& routeName);

    /**
     * @brief Announces a delay for the train service.
     *
     * @param delayMinutes The number of minutes of the delay.
     */
    void announceDelay(int delayMinutes);

private:
    std::vector<std::string> trains; ///< List of trains managed by this service.
    std::vector<std::string> routes; ///< List of routes associated with the trains.
};

#endif // TRAINS_H

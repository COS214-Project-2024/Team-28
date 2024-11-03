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

/**
 * @class CityManager
 * @brief Manages city services and citizen interactions.
 *
 * The CityManager class is responsible for notifying citizens, managing city services,
 * allocating budgets for various services, and handling citizen requests for services.
 */
class CityManager {
public:
    CityManager();

    /**
     * @brief Notifies citizens with a message.
     * @param message The message to be sent to citizens.
     */
    void notifyCitizens(const std::string& message);

    /**
     * @brief Manages various city services.
     */
    void manageServices();

    /**
     * @brief Allocates budget to a specific service type.
     * @param serviceType The type of service to allocate the budget to.
     * @param amount The amount of budget to allocate.
     */
    void allocateBudget(const std::string& serviceType, double amount);

    /**
     * @brief Requests a service of a specific type.
     * @param serviceType The type of service being requested.
     */
    void requestService(const std::string& serviceType);

    /**
     * @brief Gets a pointer to a specific service.
     * @param serviceType The type of service to retrieve.
     * @return A pointer to the requested service, or nullptr if not found.
     */
    Services* getService(const std::string& serviceType);

    /**
     * @brief Pays levies for a collection of citizens.
     * @param citizens The vector of citizens for whom levies are to be paid.
     */
    void payLevies(const std::vector<Citizen>& citizens);

private:
    std::vector<Services*> services; ///< Collection of services managed by the CityManager.
    double healthBudget; ///< Budget allocated for health services.
    double educationBudget; ///< Budget allocated for education services.
    double entertainmentBudget; ///< Budget allocated for entertainment services.
    double securityBudget; ///< Budget allocated for security services.
    double transportationBudget; ///< Budget allocated for transportation services.
};

#endif // CITYMANAGER_H

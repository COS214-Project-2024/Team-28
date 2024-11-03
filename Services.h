#ifndef SERVICES_H
#define SERVICES_H

#include <string>

/**
 * @class Services
 * @brief Abstract base class for various service types.
 *
 * This class provides a blueprint for different services with functionalities
 * such as scheduling and handling service requests.
 */
class Services {
public:
    /**
     * @brief Constructs a Services object with a specific type and capacity.
     *
     * @param serviceType The type of service being provided.
     * @param capacity The maximum capacity of the service.
     */
    Services(const std::string& serviceType, int capacity);
    
    /**
     * @brief Pure virtual function to provide the service.
     *
     * Derived classes must implement this method to define how the service
     * is provided.
     */
    virtual void provideService() = 0;

    /**
     * @brief Schedules a service at a specific time.
     *
     * @param serviceTime The time at which the service should be scheduled.
     */
    void scheduleService(const std::string& serviceTime);

    /**
     * @brief Handles a service request.
     *
     * @param request The service request to be handled.
     */
    void handleServiceRequest(const std::string& request);

    /**
     * @brief Acknowledges the allocation of a budget for the service.
     *
     * @param amount The amount of budget allocated.
     */
    void acknowledgeBudgetAllocation(double amount);

    /**
     * @brief Acknowledges a service request.
     *
     * This method is called to confirm that a service request has been received.
     */
    void acknowledgeServiceRequest();

protected:
    std::string serviceType; ///< The type of service.
    int capacity;            ///< Maximum capacity of the service.
};

#endif // SERVICES_H

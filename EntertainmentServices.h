// EntertainmentServices.h
#ifndef ENTERTAINMENTSERVICES_H
#define ENTERTAINMENTSERVICES_H

#include "Services.h"
#include <string>
#include <vector>

/**
 * @class EntertainmentServices
 * @brief Class to manage entertainment services.
 *
 * The EntertainmentServices class provides functionalities related to
 * managing entertainment services, including organizing and canceling events.
 */
class EntertainmentServices : public Services {
public:
    /**
     * @brief Default constructor for EntertainmentServices.
     */
    EntertainmentServices();

    /**
     * @brief Provides entertainment services.
     *
     * This method overrides the provideService method from the
     * Services base class, implementing the logic for providing
     * entertainment services.
     */
    void provideService() override;

    /**
     * @brief Organizes a new event.
     *
     * @param eventName The name of the event to be organized.
     */
    void organizeEvent(const std::string& eventName);

    /**
     * @brief Cancels an existing event.
     *
     * @param eventName The name of the event to be canceled.
     */
    void cancelEvent(const std::string& eventName);

private:
    std::vector<std::string> events; ///< List of organized events.
};

#endif // ENTERTAINMENTSERVICES_H

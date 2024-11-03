#ifndef SECURITYSERVICES_H
#define SECURITYSERVICES_H

#include "Services.h"
#include <string>
#include <vector>

/**
 * @class SecurityServices
 * @brief Represents the security services provided to ensure safety.
 *
 * This class extends the Services base class to provide security services 
 * such as emergency response and patrols.
 */
class SecurityServices : public Services {
public:
    /**
     * @brief Default constructor for SecurityServices.
     */
    SecurityServices();
    
    /**
     * @brief Provides the security service.
     *
     * This method implements the logic to provide security services.
     */
    void provideService() override;

    /**
     * @brief Responds to an emergency at a specified location.
     *
     * @param location The location of the emergency.
     */
    void respondToEmergency(const std::string& location);

    /**
     * @brief Conducts a patrol.
     *
     * This method implements the logic for conducting security patrols.
     */
    void conductPatrol();

private:
    std::vector<std::string> emergencyContacts; ///< List of emergency contact numbers.
};

#endif // SECURITYSERVICES_H

#ifndef SECURITYSERVICES_H
#define SECURITYSERVICES_H

#include "Services.h"
#include <string>
#include <vector>

class SecurityServices : public Services {
public:
    SecurityServices();
    void provideService() override;
    void respondToEmergency(const std::string& location);
    void conductPatrol();

private:
    std::vector<std::string> emergencyContacts;
};

#endif // SECURITYSERVICES_H
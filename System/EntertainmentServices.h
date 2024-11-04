#ifndef ENTERTAINMENTSERVICES_H
#define ENTERTAINMENTSERVICES_H

#include "Services.h"
#include <string>
#include <vector>

class EntertainmentServices : public Services {
public:
    EntertainmentServices();
    void provideService() override;
    void organizeEvent(const std::string& eventName);
    void cancelEvent(const std::string& eventName);

private:
    std::vector<std::string> events;
};

#endif // ENTERTAINMENTSERVICES_H
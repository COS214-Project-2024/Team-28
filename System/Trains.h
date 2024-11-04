#ifndef TRAINS_H
#define TRAINS_H

#include "Services.h"
#include <string>
#include <vector>

class Trains : public Services {
public:
    Trains();
    void provideService() override;
    void addTrain(const std::string& trainName);
    void removeTrain(const std::string& trainName);
    void scheduleTrain(const std::string& routeName);
    void announceDelay(int delayMinutes);

private:
    std::vector<std::string> trains;
    std::vector<std::string> routes;
};

#endif // TRAINS_H
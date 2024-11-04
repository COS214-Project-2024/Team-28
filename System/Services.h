#ifndef SERVICES_H
#define SERVICES_H

#include <string>

class Services {
public:
    Services(const std::string& serviceType, int capacity);
    virtual void provideService() = 0;
    void scheduleService(const std::string& serviceTime);
    void handleServiceRequest(const std::string& request);
    void acknowledgeBudgetAllocation(double amount);
    void acknowledgeServiceRequest();

protected:
    std::string serviceType;
    int capacity;
};

#endif // SERVICES_H
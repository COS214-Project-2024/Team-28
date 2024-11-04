#ifndef HEALTHSERVICES_H
#define HEALTHSERVICES_H

#include "Services.h"
#include <string>
#include <vector>

class HealthServices : public Services {
public:
    HealthServices();
    void provideService() override;
    void admitPatient(const std::string& patientName);
    void provideTreatment(const std::string& patientName);

private:
    std::vector<std::string> patients;
};

#endif // HEALTHSERVICES_H
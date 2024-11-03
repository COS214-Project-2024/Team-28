// HealthServices.h
#ifndef HEALTHSERVICES_H
#define HEALTHSERVICES_H

#include "Services.h"
#include <string>
#include <vector>

/**
 * @class HealthServices
 * @brief Represents the health services provided by the government.
 *
 * The HealthServices class is responsible for managing health-related services,
 * including admitting patients and providing treatments.
 */
class HealthServices : public Services {
public:
    /**
     * @brief Constructs a HealthServices object.
     */
    HealthServices();

    /**
     * @brief Provides health services to the public.
     *
     * This method will implement the necessary logic to offer health services.
     */
    void provideService() override;

    /**
     * @brief Admits a patient to the health service.
     *
     * @param patientName The name of the patient to be admitted.
     */
    void admitPatient(const std::string& patientName);

    /**
     * @brief Provides treatment to a specified patient.
     *
     * @param patientName The name of the patient receiving treatment.
     */
    void provideTreatment(const std::string& patientName);

private:
    std::vector<std::string> patients; ///< List of patients currently admitted to the health service.
};

#endif // HEALTHSERVICES_H

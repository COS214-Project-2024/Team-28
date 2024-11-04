#include "HealthServices.h"
#include <iostream>

HealthServices::HealthServices() : Services("Health", 100) {}

void HealthServices::provideService() {
    std::cout << "Providing health services..." << std::endl;
}

void HealthServices::admitPatient(const std::string& patientName) {
    patients.push_back(patientName);
    std::cout << "Admitting patient: " << patientName << std::endl;
}

void HealthServices::provideTreatment(const std::string& patientName) {
    std::cout << "Providing treatment to patient: " << patientName << std::endl;
}
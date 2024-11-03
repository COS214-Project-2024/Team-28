// ResidentialBuilding.cpp

#include "ResidentialBuilding.h"

ResidentialBuilding::ResidentialBuilding(std::string addr, double cost, int cap)
    : address(addr), maintenanceCost(cost), capacity(cap) {}

void ResidentialBuilding::addResidents(const std::vector<Citizen>& newResidents) {
    residents.insert(residents.end(), newResidents.begin(), newResidents.end());
}

void ResidentialBuilding::removeResidents(const std::vector<Citizen>& leavingResidents) {
    // Logic to remove residents based on 'leavingResidents' list
}

std::vector<Citizen>::iterator ResidentialBuilding::getResidents() {
    return residents.begin(); 
}

int ResidentialBuilding::getOccupancy() const {
    return residents.size();
}

ResidentialBuilding* ResidentialBuilding::create() {
    return new ResidentialBuilding("Default Address", 0.0, 0); // Placeholder values
}

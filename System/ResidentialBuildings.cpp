#include "ResidentialBuildings.h"

// House implementation
House::House() : ResidentialBuilding(), address(""), numberOfResidents(0), buildingCost(10) {}

House::House(std::string address, int numberOfResidents)
    : address(address), numberOfResidents(numberOfResidents), buildingCost(10) {}

float House::getBuildCost() {
    return buildingCost;
}

int House::getNumberOfResidents() {
    return numberOfResidents;
}

std::string House::getAddress() {
    return address;
}

void House::print() const {
    std::cout << "----------" << std::endl;
    std::cout << "House Details: " << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Number Of Residents: " << numberOfResidents << std::endl;
    std::cout << "----------" << std::endl;
}

// Flat implementation
Flat::Flat() : ResidentialBuilding(), address(""), numberOfResidents(0), buildingCost(100) {}

Flat::Flat(std::string address, int numberOfResidents)
    : address(address), numberOfResidents(numberOfResidents), buildingCost(100) {}

float Flat::getBuildCost() {
    return buildingCost;
}

int Flat::getnumberOfResidents() {
    return numberOfResidents;
}

std::string Flat::getAddress() {
    return address;
}

void Flat::print() const {
    std::cout << "----------" << std::endl;
    std::cout << "Flat Details: " << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Number Of Residents: " << numberOfResidents << std::endl;
    std::cout << "----------" << std::endl;
}

// TownHouse implementation
TownHouse::TownHouse() : ResidentialBuilding(), address(""), numberOfResidents(0), buildingCost(110) {}

TownHouse::TownHouse(std::string address, int numberOfResidents)
    : address(address), numberOfResidents(numberOfResidents), buildingCost(110) {}

float TownHouse::getBuildCost() {
    return buildingCost;
}

int TownHouse::getnumberOfResidents() {
    return numberOfResidents;
}

std::string TownHouse::getAddress() {
    return address;
}

void TownHouse::print() const {
    std::cout << "----------" << std::endl;
    std::cout << "Townhouse Details: " << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Number Of Residents: " << numberOfResidents << std::endl;
    std::cout << "----------" << std::endl;
}

// Estate implementation
Estate::Estate() : ResidentialBuilding(), address(""), numberOfUnits(0), numberOfResidents(0), buildingCost(1000) {}

Estate::Estate(std::string address, int numberOfUnits, int numberOfResidents)
    : address(address), numberOfUnits(numberOfUnits), numberOfResidents(numberOfResidents), buildingCost(1000) {}

float Estate::getBuildCost() {
    return buildingCost;
}

int Estate::getNumberOfResidents() {
    return numberOfResidents;
}

int Estate::avergeResidentsPerUnit() {
    avgPerUnit = numberOfResidents / numberOfUnits;
    return avgPerUnit;
}

std::string Estate::getAddress() {
    return address;
}

void Estate::print() const {
    std::cout << "----------" << std::endl;
    std::cout << "Estate Details: " << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Number of Units: " << numberOfUnits << std::endl;
    std::cout << "Number Of Residents: " << numberOfResidents << std::endl;
    std::cout << "Average Number Of Residents per unit: " << avgPerUnit << std::endl;
    std::cout << "----------" << std::endl;
}
#include "ResidentialBuildings.h"

// House implementation
House::House() : ResidentialBuilding(), address(""), numberOfResidents(0), buildingCost(10) {}

House::House(std::string address, int numberOfResidents)
    : address(address), numberOfResidents(numberOfResidents), buildingCost(10) {}

float House::getBuildCost() const{
    return buildingCost;
}

int House::getNumberOfResidents() const{
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

float Flat::getBuildCost() const{
    return buildingCost;
}

int Flat::getNumberOfResidents()const{
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

float TownHouse::getBuildCost() const{
    return buildingCost;
}

int TownHouse::getNumberOfResidents() const{
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
//Estate implementation
Estate::Estate() : ResidentialBuilding(), maxCapacity(10) { // Default max capacity
        this->address = "";
        this->buildingCost = 1000;
        this->numberOfResidents = 0;
    }


Estate:: Estate(std::string address, int maxCapacity) : ResidentialBuilding(), maxCapacity(maxCapacity) {
        this->address = address;
        this->buildingCost = 1000;
        this->numberOfResidents = 0;
    }

float Estate::getBuildCost() const {
    return this->buildingCost; // return building cost for comparisons
}

 void Estate:: createAndAddTownHouse(std::string address, int numberOfResidents) {
        if (numberUnits() < maxCapacity) {
            TownHouse newTownHouse(address, numberOfResidents);
            townhouses.push_back(newTownHouse);
            this->numberOfResidents += newTownHouse.getNumberOfResidents();
            this->buildingCost += newTownHouse.getBuildCost();
        } else {
            std::cout << "Error: Maximum capacity for Estate reached." << std::endl;
        }
    }
void Estate::createAndAddHouse(std::string address, int numberOfResidents) {
        if (numberUnits() < maxCapacity) {
            House newHouse(address, numberOfResidents);
            houses.push_back(newHouse);
            this->numberOfResidents += newHouse.getNumberOfResidents();
            this->buildingCost += newHouse.getBuildCost();
        } else {
            std::cout << "Error: Maximum capacity for Estate reached." << std::endl;
        }
    }

void Estate::createAndAddFlat(std::string address, int numberOfResidents) {
        if (numberUnits() < maxCapacity) {
            Flat newFlat(address, numberOfResidents);
            flats.push_back(newFlat);
            this->numberOfResidents += newFlat.getNumberOfResidents();
            this->buildingCost += newFlat.getBuildCost();
        } else {
            std::cout << "Error: Maximum capacity for Estatereached." << std::endl;
        }
    }

int Estate::getNumberOfResidents() const {
    return this->numberOfResidents;
}



std::string Estate::getAddress() const{
    return address;
}

int Estate::numberUnits() const{
        return (houses.size() + flats.size()+townhouses.size());
    }

void Estate::print() const {
        std::cout << "----------" << std::endl;
        std::cout << "Estate Details: " << std::endl;
        std::cout << "Address: " << address << std::endl;
        std::cout << "Estate Composition: " << std::endl;
        std::cout << "Total Number of TownHouses: " << townhouses.size()<< std::endl;
        std::cout << "Total Number of Houses: " << houses.size()<< std::endl;
        std::cout << "Total Number of Flats: " << flats.size() << std::endl;
        std::cout << "Total Number Of Residents: " << numberOfResidents << std::endl;
        std::cout << "Building Cost: " << buildingCost << std::endl;
        std::cout << "----------" << std::endl;
    }
#include "LandMarks.h"

// Park class implementations
Park::Park() : Landmark() {
    address = "";
    nameOfPark = "";
    dateEstablished = "";
    condition = 0;
    buildingCost = 90;
}

Park::Park(std::string address, std::string nameOfPark, std::string date, int condition)
    : address(address), nameOfPark(nameOfPark), dateEstablished(date), condition(condition), buildingCost(90) {}

float Park::getBuildCost() {
    return buildingCost;
}

int Park::getCondition() {
    return condition;
}

std::string Park::getAddress() {
    return address;
}

void Park::print() const {
    std::cout << "----------" << std::endl;
    std::cout << "Park Details: " << std::endl;
    std::cout << "Name: " << nameOfPark << std::endl;
    std::cout << "Date Opened: " << dateEstablished << std::endl;
    std::cout << "Condition: " << condition << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "----------" << std::endl;
}

// Monument class implementations
Monument::Monument() : Landmark() {
    location = "";
    nameOfMonument = "";
    dateEstablished = "";
    materialUsed = "";
    condition = 0;
    buildingCost = 90;
}

Monument::Monument(std::string location, std::string nameOfMonument, std::string date, std::string material, int condition)
    : location(location), nameOfMonument(nameOfMonument), materialUsed(material), dateEstablished(date), condition(condition), buildingCost(90) {
}

float Monument::getBuildCost() {
    return buildingCost;
}

int Monument::getCondition() {
    return condition;
}

void Monument::print() const {
    std::cout << "----------" << std::endl;
    std::cout << "Monument Details: " << std::endl;
    std::cout << "Name: " << nameOfMonument << std::endl;
    std::cout << "Date Created: " << dateEstablished << std::endl;
    std::cout << "Material: " << materialUsed << std::endl;
    std::cout << "Condition: " << condition << std::endl;
    std::cout << "Location: " << location << std::endl;
    std::cout << "----------" << std::endl;
}

// Center class implementations
Center::Center() : Landmark() {
    address = "";
    nameOfCenter = "";
    description = "";
    dateEstablished = "";
    condition = 0;
    buildingCost = 90;
}

Center::Center(std::string address, std::string nameOfCenter, std::string date, int condition)
    : address(address), nameOfCenter(nameOfCenter), dateEstablished(date), condition(condition), buildingCost(90) {}

float Center::getBuildCost() {
    return buildingCost;
}

int Center::getCondition() {
    return condition;
}

void Center::print() const {
    std::cout << "----------" << std::endl;
    std::cout << "Center Details: " << std::endl;
    std::cout << "Name: " << nameOfCenter << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Date Opened: " << dateEstablished << std::endl;
    std::cout << "Condition: " << condition << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "----------" << std::endl;
}
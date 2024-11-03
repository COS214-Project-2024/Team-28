#ifndef RESIDENTIALBUILDINGS_H
#define RESIDENTIALBUILDINGS_H

#include <iostream>
#include "Building.h"
#include "IndustrialBuilding.h"

class House : public ResidentialBuilding {
public:
    House();
    House(std::string address, int numberOfResidents);
    float getBuildCost();
    ~House() = default;
    int getNumberOfResidents();
    std::string getAddress();
    void print() const override;

private:
    std::string address;
    int numberOfResidents;
    float buildingCost;
};

class Flat : public ResidentialBuilding {
public:
    Flat();
    Flat(std::string address, int numberOfResidents);
    float getBuildCost();
    ~Flat() = default;
    int getnumberOfResidents();
    std::string getAddress();
    void print() const override;

private:
    std::string address;
    int numberOfResidents;
    float buildingCost;
};

class TownHouse : public ResidentialBuilding {
public:
    TownHouse();
    TownHouse(std::string address, int numberOfResidents);
    float getBuildCost();
    ~TownHouse() = default;
    int getnumberOfResidents();
    std::string getAddress();
    void print() const override;

private:
    std::string address;
    int numberOfResidents;
    float buildingCost;
};

class Estate : public ResidentialBuilding {
public:
    Estate();
    Estate(std::string address, int numberOfUnits, int numberOfResidents);
    float getBuildCost();
    ~Estate() = default;
    int getNumberOfResidents();
    int avergeResidentsPerUnit();
    std::string getAddress();
    void print() const override;

private:
    std::string address;
    int numberOfUnits;
    int numberOfResidents;
    int avgPerUnit;
    float buildingCost;
};

#endif // RESIDENTIALBUILDINGS_H
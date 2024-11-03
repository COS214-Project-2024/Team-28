#ifndef RESIDENTIALBUILDINGS_H
#define RESIDENTIALBUILDINGS_H

#include <iostream>
#include <vector>
#include "Building.h"

class House : public ResidentialBuilding {
public:
    House();
    House(std::string address, int numberOfResidents);
    float getBuildCost() const;
    ~House() = default;
    int getNumberOfResidents() const;
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
    float getBuildCost() const;
    ~Flat() = default;
    int getNumberOfResidents() const;
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
    float getBuildCost() const;
    ~TownHouse() = default;
    int getNumberOfResidents() const;
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
    Estate(std::string address, int maxCapacity);

    // Method to create and add a new TownHouse
    void createAndAddTownHouse(std::string address, int numberOfResidents);

    // Method to create and add a new House
    void createAndAddHouse(std::string address, int numberOfResidents);

    // Method to create and add a new Flat
    void createAndAddFlat(std::string address, int numberOfResidents);

    float getBuildCost() const;

    ~Estate() = default;

    int getNumberOfResidents() const;

    std::string getAddress() const;

    int numberUnits() const;

    void print() const override;

private:
    std::string address;               // address
    float buildingCost;                // cost to build the house, default is 1000             
    int numberOfResidents;  
    int maxCapacity;                   // Maximum number of buildings

    std::vector<TownHouse> townhouses;
    std::vector<House> houses;
    std::vector<Flat> flats;
};



#endif

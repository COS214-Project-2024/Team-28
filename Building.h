#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
//ABSTRACT PRODUCTS

class Building{ //
    public:
        Building() = default;
        ~Building() = default;
        virtual void print() const = 0;

};

class ResidentialBuilding : public Building {
public:
    virtual ~ResidentialBuilding() = default;
};


class CommercialBuilding : public Building {
public:
    virtual ~CommercialBuilding() = default;
    virtual float getBuildCost() const = 0;
    virtual std::string getAddress() const = 0;
    virtual void print() const = 0;
};

class Landmark : public Building {
public:
    virtual ~Landmark() = default;
};

#endif

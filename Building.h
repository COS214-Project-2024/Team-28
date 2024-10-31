#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
#include "IndustrialBuilding.h"
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
};

// IndustrialBuilding removed here - on its own header file.
class Landmark : public Building {
public:
    virtual ~Landmark() = default;
};

#endif

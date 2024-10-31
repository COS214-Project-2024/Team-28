#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include <iostream>
#include "Building.h"
#include "ResidentialBuildings.h"


//ABSTRACT FACTROY 

class BuildingFactory{
public:
    virtual ~BuildingFactory() = default;
    //Residential Buildings
    virtual ResidentialBuilding* createHouse() const = 0;
    virtual ResidentialBuilding* createFlat() const = 0;
    virtual ResidentialBuilding* createTownHouse() const = 0;
    virtual ResidentialBuilding* createEstate() const = 0;

    //Commecrial Buildings
    virtual CommercialBuilding* createShop() const = 0;
    virtual CommercialBuilding* createOffice() const = 0;
    virtual CommercialBuilding* createMall() const = 0;


    //Industrial Buildings
    virtual IndustrialBuilding* createFactory() const = 0;
    virtual IndustrialBuilding* createWarehouse() const = 0;
    virtual IndustrialBuilding* createPlant() const = 0;

    //LandMarks 
    virtual Landmark* createPark() const = 0;
    virtual Landmark* createMonument() const = 0;
    virtual Landmark* createCenters() const = 0;

    //Industrials
};




#endif 
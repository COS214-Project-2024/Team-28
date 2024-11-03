// CommericlalBuildingFactory.h
#ifndef LANDMARKFACTORY_H
#define LANDMARKFACTORY_H

#include "BuildingFactory.h"
#include "LandMarks.h"
#include "IndustrialBuilding.h"

class LandMarkFactory : public BuildingFactory {
public:
    Landmark* createPark() const override { 
        return new Park();
    }
    Landmark* createMonument() const override { 
        return new Monument(); 
    }
    Landmark* createCenters() const override { 
        return new Center();
    }



    

    // Returns nullptr for other types as CommercialBuildingFactory only creates residential buildings
    

    ResidentialBuilding* createHouse() const override {return nullptr;}
    ResidentialBuilding* createFlat() const override {return nullptr;}
    ResidentialBuilding* createTownHouse() const override {return nullptr;}
    ResidentialBuilding* createEstate() const override { return nullptr; }
    CommercialBuilding* createShop() const override  {return nullptr;}
    CommercialBuilding* createOffice() const override  {return nullptr;}
    CommercialBuilding* createMall() const override {return nullptr;}
    IndustrialBuilding* createFactory() const override { return nullptr; }
    IndustrialBuilding* createWarehouse() const override { return nullptr; }
    IndustrialBuilding* createPlant() const override { return nullptr;}
    
};

#endif

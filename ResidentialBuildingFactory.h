// ResidentialBuildingFactory.h
#ifndef RESIDENTIALBUILDINGFACTORY_H
#define RESIDENTIALBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "ResidentialBuildings.h"

class ResidentialBuildingFactory : public BuildingFactory {
public:
    ResidentialBuilding* createHouse() const override {
        return new House();
    }

    ResidentialBuilding* createFlat() const override {
        return new Flat();
    }

    ResidentialBuilding* createTownHouse() const override {
        return new TownHouse();
    }

    ResidentialBuilding* createEstate() const override {
        return new Estate();
    }



    

    // Returns nullptr for other types as ResidentialBuildingFactory only creates residential buildings
    CommercialBuilding* createShop() const override { return nullptr; }
    CommercialBuilding* createOffice() const override { return nullptr; }
    CommercialBuilding* createMall() const override { return nullptr; }
    IndustrialBuilding* createFactory() const override { return nullptr; }
    IndustrialBuilding* createWarehouse() const override { return nullptr; }
    IndustrialBuilding* createPlant() const override { return nullptr; }
    Landmark* createPark() const override { return nullptr; }
    Landmark* createMonument() const override { return nullptr; }
    Landmark* createCenters() const override { return nullptr;}
};

#endif

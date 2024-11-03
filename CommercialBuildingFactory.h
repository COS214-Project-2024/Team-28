// CommericlalBuildingFactory.h
#ifndef COMMERCIALBUILDINGFACTORY_H
#define COMMERCIALBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "CommercialBuildings.h"

class CommericalBuildingFactory : public BuildingFactory {
public:
    CommercialBuilding* createShop() const override { 
        return new Shop();
     }
    CommercialBuilding* createOffice() const override {
        return new Office();
    }
    CommercialBuilding* createMall() const override {
        return new Mall();
    }

    ResidentialBuilding* createHouse() const override {return nullptr;}
    ResidentialBuilding* createFlat() const override {return nullptr;}
    ResidentialBuilding* createTownHouse() const override {return nullptr;}
    ResidentialBuilding* createEstate() const override { return nullptr; }
    IndustrialBuilding* createFactory() const override { return nullptr; }
    IndustrialBuilding* createWarehouse() const override { return nullptr; }
    IndustrialBuilding* createPlant() const override { return nullptr;}
    Landmark* createPark() const override { return nullptr; }
    Landmark* createMonument() const override { return nullptr; }
    Landmark* createCenters() const override { return nullptr;}
};

#endif

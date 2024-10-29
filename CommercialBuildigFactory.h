// CommericlalBuildingFactory.h
#ifndef COMMERCIALBUILDINGFACTORY_H
#define COMMERCIALIALBUILDINGFACTORY_H

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



    

    // Returns nullptr for other types as CommercialBuildingFactory only creates residential buildings
    

    ResidentialBuilding* createHouse() const override {return nullptr;}
    ResidentialBuilding* createFlat() const override {return nullptr;}
    ResidentialBuilding* createTownHouse() const override {return nullptr;}
    ResidentialBuilding* createEstate() const override { return nullptr; }
    IndustrialBuilding* createFactory() const override { return nullptr; }
    IndustrialBuilding* createWarehouse() const override { return nullptr; }
    Landmark* createPark() const override { return nullptr; }
    Landmark* createMonument() const override { return nullptr; }
};

#endif

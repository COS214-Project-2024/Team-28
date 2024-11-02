#ifndef INDUSTRIALFACTORY_H
#define INDUSTRIALFACTORY_H

#include "BuildingFactory.h"
#include "IndustrialBuilding.h"
#include "Factories.h"
#include "Warehouses.h"

// Industrial Factory
class IndustrialFactory : public BuildingFactory {
public:
    IndustrialBuilding* createFactory() const override {
        return new Factories(new SteelBuilder());
    }

    IndustrialBuilding* createWarehouse() const override {
        return new Warehouses();
    }

    IndustrialBuilding* createPlant() const override {
        return nullptr;
    }

    // Other required overrides from BuildingFactory
    ResidentialBuilding* createHouse() const override { return nullptr; }
    ResidentialBuilding* createFlat() const override { return nullptr; }
    ResidentialBuilding* createTownHouse() const override { return nullptr; }
    ResidentialBuilding* createEstate() const override { return nullptr; }
    CommercialBuilding* createShop() const override { return nullptr; }
    CommercialBuilding* createOffice() const override { return nullptr; }
    CommercialBuilding* createMall() const override { return nullptr; }
    Landmark* createPark() const override { return nullptr; }
    Landmark* createMonument() const override { return nullptr; }
    Landmark* createCenters() const override { return nullptr; }
};

#endif // INDUSTRIALFACTORY_H
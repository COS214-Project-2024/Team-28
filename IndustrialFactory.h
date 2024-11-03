#ifndef INDUSTRIALFACTORY_H
#define INDUSTRIALFACTORY_H

#include "BuildingFactory.h"
#include "IndustrialBuilding.h"
#include "Factories.h"
#include "Warehouses.h"

// Industrial Factory

/**
 * @class IndustrialFactory
 * @brief A factory for creating industrial buildings.
 *
 * The IndustrialFactory class implements the BuildingFactory interface,
 * providing concrete methods to create different types of industrial 
 * buildings such as factories and warehouses.
 */
class IndustrialFactory : public BuildingFactory {
public:
    /**
     * @brief Creates a new factory instance.
     *
     * This method returns a pointer to a newly created Factories object.
     * It creates a factory with a new SteelBuilder as its material hub.
     *
     * @return A pointer to the created IndustrialBuilding (Factories).
     */
    IndustrialBuilding* createFactory() const override {
        return new Factories(new SteelBuilder());
    }

    /**
     * @brief Creates a new warehouse instance.
     *
     * This method returns a pointer to a newly created Warehouses object.
     *
     * @return A pointer to the created IndustrialBuilding (Warehouses).
     */
    IndustrialBuilding* createWarehouse() const override {
        return new Warehouses();
    }

    /**
     * @brief Creates a new plant instance.
     *
     * This method currently returns a nullptr as the plant creation is not implemented.
     *
     * @return A pointer to an IndustrialBuilding (nullptr).
     */
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

// CommercialBuildingFactory.h
#ifndef COMMERCIALBUILDINGFACTORY_H
#define COMMERCIALBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "CommercialBuildings.h"

/**
 * @class CommercialBuildingFactory
 * @brief Factory class for creating commercial buildings.
 *
 * The CommercialBuildingFactory class is responsible for creating
 * instances of commercial building types such as shops, offices, and malls.
 */
class CommercialBuildingFactory : public BuildingFactory {
public:
    /**
     * @brief Creates a new shop instance.
     * @return Pointer to a new Shop object.
     */
    CommercialBuilding* createShop() const override { 
        return new Shop();
    }

    /**
     * @brief Creates a new office instance.
     * @return Pointer to a new Office object.
     */
    CommercialBuilding* createOffice() const override {
        return new Office();
    }

    /**
     * @brief Creates a new mall instance.
     * @return Pointer to a new Mall object.
     */
    CommercialBuilding* createMall() const override {
        return new Mall();
    }

    // The following methods return nullptr as this factory does not create these building types.

    /**
     * @brief Creates a new house instance.
     * @return Always returns nullptr.
     */
    ResidentialBuilding* createHouse() const override { return nullptr; }

    /**
     * @brief Creates a new flat instance.
     * @return Always returns nullptr.
     */
    ResidentialBuilding* createFlat() const override { return nullptr; }

    /**
     * @brief Creates a new townhouse instance.
     * @return Always returns nullptr.
     */
    ResidentialBuilding* createTownHouse() const override { return nullptr; }

    /**
     * @brief Creates a new estate instance.
     * @return Always returns nullptr.
     */
    ResidentialBuilding* createEstate() const override { return nullptr; }

    /**
     * @brief Creates a new factory instance.
     * @return Always returns nullptr.
     */
    IndustrialBuilding* createFactory() const override { return nullptr; }

    /**
     * @brief Creates a new warehouse instance.
     * @return Always returns nullptr.
     */
    IndustrialBuilding* createWarehouse() const override { return nullptr; }

    /**
     * @brief Creates a new plant instance.
     * @return Always returns nullptr.
     */
    IndustrialBuilding* createPlant() const override { return nullptr; }

    /**
     * @brief Creates a new park instance.
     * @return Always returns nullptr.
     */
    Landmark* createPark() const override { return nullptr; }

    /**
     * @brief Creates a new monument instance.
     * @return Always returns nullptr.
     */
    Landmark* createMonument() const override { return nullptr; }

    /**
     * @brief Creates a new center instance.
     * @return Always returns nullptr.
     */
    Landmark* createCenters() const override { return nullptr; }
};

#endif // COMMERCIALBUILDINGFACTORY_H

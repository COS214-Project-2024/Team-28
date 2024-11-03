#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include <iostream>
#include "Building.h"
#include "ResidentialBuildings.h"

// ABSTRACT FACTORY

/**
 * @class BuildingFactory
 * @brief An abstract factory class for creating different types of buildings.
 *
 * This class defines the interface for creating various building types,
 * including residential, commercial, industrial, and landmark buildings.
 */
class BuildingFactory {
public:
    /**
     * @brief Default virtual destructor for the BuildingFactory class.
     */
    virtual ~BuildingFactory() = default;

    // Residential Buildings
    /**
     * @brief Creates a new house.
     * @return A pointer to a new ResidentialBuilding representing a house.
     */
    virtual ResidentialBuilding* createHouse() const = 0;

    /**
     * @brief Creates a new flat.
     * @return A pointer to a new ResidentialBuilding representing a flat.
     */
    virtual ResidentialBuilding* createFlat() const = 0;

    /**
     * @brief Creates a new townhouse.
     * @return A pointer to a new ResidentialBuilding representing a townhouse.
     */
    virtual ResidentialBuilding* createTownHouse() const = 0;

    /**
     * @brief Creates a new estate.
     * @return A pointer to a new ResidentialBuilding representing an estate.
     */
    virtual ResidentialBuilding* createEstate() const = 0;

    // Commercial Buildings
    /**
     * @brief Creates a new shop.
     * @return A pointer to a new CommercialBuilding representing a shop.
     */
    virtual CommercialBuilding* createShop() const = 0;

    /**
     * @brief Creates a new office.
     * @return A pointer to a new CommercialBuilding representing an office.
     */
    virtual CommercialBuilding* createOffice() const = 0;

    /**
     * @brief Creates a new mall.
     * @return A pointer to a new CommercialBuilding representing a mall.
     */
    virtual CommercialBuilding* createMall() const = 0;

    // Industrial Buildings
    /**
     * @brief Creates a new factory.
     * @return A pointer to a new IndustrialBuilding representing a factory.
     */
    virtual IndustrialBuilding* createFactory() const = 0;

    /**
     * @brief Creates a new warehouse.
     * @return A pointer to a new IndustrialBuilding representing a warehouse.
     */
    virtual IndustrialBuilding* createWarehouse() const = 0;

    /**
     * @brief Creates a new plant.
     * @return A pointer to a new IndustrialBuilding representing a plant.
     */
    virtual IndustrialBuilding* createPlant() const = 0;

    // Landmarks
    /**
     * @brief Creates a new park.
     * @return A pointer to a new Landmark representing a park.
     */
    virtual Landmark* createPark() const = 0;

    /**
     * @brief Creates a new monument.
     * @return A pointer to a new Landmark representing a monument.
     */
    virtual Landmark* createMonument() const = 0;

    /**
     * @brief Creates a new center.
     * @return A pointer to a new Landmark representing a center.
     */
    virtual Landmark* createCenters() const = 0;
};

#endif // BUILDINGFACTORY_H

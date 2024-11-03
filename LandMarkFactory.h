#ifndef LANDMARKFACTORY_H
#define LANDMARKFACTORY_H

#include "BuildingFactory.h"
#include "LandMarks.h"

/**
 * @class LandMarkFactory
 * @brief A factory for creating landmark buildings.
 *
 * The LandMarkFactory class implements the BuildingFactory interface,
 * providing concrete methods to create various types of landmarks
 * such as parks, monuments, and centers.
 */
class LandMarkFactory : public BuildingFactory {
public:
    /**
     * @brief Creates a new park instance.
     *
     * This method returns a pointer to a newly created Park object.
     *
     * @return A pointer to the created Landmark (Park).
     */
    Landmark* createPark() const override { 
        return new Park();
    }

    /**
     * @brief Creates a new monument instance.
     *
     * This method returns a pointer to a newly created Monument object.
     *
     * @return A pointer to the created Landmark (Monument).
     */
    Landmark* createMonument() const override { 
        return new Monument(); 
    }

    /**
     * @brief Creates a new center instance.
     *
     * This method returns a pointer to a newly created Center object.
     *
     * @return A pointer to the created Landmark (Center).
     */
    Landmark* createCenters() const override { 
        return new Center();
    }

    // Returns nullptr for other types as this factory only creates landmarks.

    ResidentialBuilding* createHouse() const override { return nullptr; }
    ResidentialBuilding* createFlat() const override { return nullptr; }
    ResidentialBuilding* createTownHouse() const override { return nullptr; }
    ResidentialBuilding* createEstate() const override { return nullptr; }
    CommercialBuilding* createShop() const override { return nullptr; }
    CommercialBuilding* createOffice() const override { return nullptr; }
    CommercialBuilding* createMall() const override { return nullptr; }
    IndustrialBuilding* createFactory() const override { return nullptr; }
    IndustrialBuilding* createWarehouse() const override { return nullptr; }
    IndustrialBuilding* createPlant() const override { return nullptr; }
};

#endif // LANDMARKFACTORY_H

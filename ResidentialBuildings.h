#ifndef RESIDENTIALBUILDINGS_H
#define RESIDENTIALBUILDINGS_H

#include <iostream>
#include <vector>
#include "Building.h"

/**
 * @class House
 * @brief Represents a residential house.
 *
 * This class includes methods for managing house properties such as address,
 * number of residents, and building cost.
 */
class House : public ResidentialBuilding {
public:
    House();
    House(std::string address, int numberOfResidents);

    /**
     * @brief Calculates the building cost.
     * 
     * @return The cost of building the house.
     */
    float getBuildCost() const;

    /**
     * @brief Gets the number of residents.
     * 
     * @return The number of residents in the house.
     */
    int getNumberOfResidents() const;

    /**
     * @brief Gets the address of the house.
     * 
     * @return The address as a string.
     */
    std::string getAddress();

    /**
     * @brief Prints the details of the house.
     */
    void print() const override;

    ~House() = default;

private:
    std::string address;       ///< The address of the house.
    int numberOfResidents;     ///< Number of residents living in the house.
    float buildingCost;        ///< The cost of building the house.
};

/**
 * @class Flat
 * @brief Represents a residential flat.
 *
 * This class includes methods for managing flat properties such as address,
 * number of residents, and building cost.
 */
class Flat : public ResidentialBuilding {
public:
    Flat();
    Flat(std::string address, int numberOfResidents);

    /**
     * @brief Calculates the building cost.
     * 
     * @return The cost of building the flat.
     */
    float getBuildCost() const;

    /**
     * @brief Gets the number of residents.
     * 
     * @return The number of residents in the flat.
     */
    int getNumberOfResidents() const;

    /**
     * @brief Gets the address of the flat.
     * 
     * @return The address as a string.
     */
    std::string getAddress();

    /**
     * @brief Prints the details of the flat.
     */
    void print() const override;

    ~Flat() = default;

private:
    std::string address;       ///< The address of the flat.
    int numberOfResidents;     ///< Number of residents living in the flat.
    float buildingCost;        ///< The cost of building the flat.
};

/**
 * @class TownHouse
 * @brief Represents a residential townhouse.
 *
 * This class includes methods for managing townhouse properties such as address,
 * number of residents, and building cost.
 */
class TownHouse : public ResidentialBuilding {
public:
    TownHouse();
    TownHouse(std::string address, int numberOfResidents);

    /**
     * @brief Calculates the building cost.
     * 
     * @return The cost of building the townhouse.
     */
    float getBuildCost() const;

    /**
     * @brief Gets the number of residents.
     * 
     * @return The number of residents in the townhouse.
     */
    int getNumberOfResidents() const;

    /**
     * @brief Gets the address of the townhouse.
     * 
     * @return The address as a string.
     */
    std::string getAddress();

    /**
     * @brief Prints the details of the townhouse.
     */
    void print() const override;

    ~TownHouse() = default;

private:
    std::string address;       ///< The address of the townhouse.
    int numberOfResidents;     ///< Number of residents living in the townhouse.
    float buildingCost;        ///< The cost of building the townhouse.
};

/**
 * @class Estate
 * @brief Represents a residential estate that can contain multiple types of residential buildings.
 *
 * This class includes methods for adding new residential buildings and calculating the total 
 * building costs and resident statistics.
 */
class Estate : public ResidentialBuilding {
public:
    Estate();
    Estate(std::string address, int maxCapacity);

    /**
     * @brief Creates and adds a new TownHouse to the estate.
     * 
     * @param address The address of the townhouse.
     * @param numberOfResidents The number of residents in the townhouse.
     */
    void createAndAddTownHouse(std::string address, int numberOfResidents);

    /**
     * @brief Creates and adds a new House to the estate.
     * 
     * @param address The address of the house.
     * @param numberOfResidents The number of residents in the house.
     */
    void createAndAddHouse(std::string address, int numberOfResidents);

    /**
     * @brief Creates and adds a new Flat to the estate.
     * 
     * @param address The address of the flat.
     * @param numberOfResidents The number of residents in the flat.
     */
    void createAndAddFlat(std::string address, int numberOfResidents);

    /**
     * @brief Calculates the total building cost of the estate.
     * 
     * @return The total building cost of all buildings in the estate.
     */
    float getBuildCost() const;

    /**
     * @brief Gets the total number of residents in the estate.
     * 
     * @return The total number of residents in the estate.
     */
    int getNumberOfResidents() const;

    /**
     * @brief Gets the address of the estate.
     * 
     * @return The address as a string.
     */
    std::string getAddress() const;

    /**
     * @brief Gets the total number of units in the estate.
     * 
     * @return The total number of residential units.
     */
    int numberUnits() const;

    /**
     * @brief Prints the details of the estate and its buildings.
     */
    void print() const override;

    ~Estate() = default;

private:
    std::string address;               ///< The address of the estate.
    float buildingCost;                ///< The cost to build the estate.
    int numberOfResidents;             ///< Total number of residents in the estate.
    int maxCapacity;                   ///< Maximum number of buildings in the estate.

    std::vector<TownHouse> townhouses; ///< Collection of townhouses in the estate.
    std::vector<House> houses;         ///< Collection of houses in the estate.
    std::vector<Flat> flats;           ///< Collection of flats in the estate.
};

#endif // RESIDENTIALBUILDINGS_H

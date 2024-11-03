#ifndef LANDMARKS_H
#define LANDMARKS_H

#include <iostream>
#include "Building.h"

/**
 * @class Park
 * @brief Represents a park landmark.
 *
 * The Park class encapsulates the details of a park, including its address,
 * name, establishment date, and condition. It also provides methods to retrieve
 * its build cost and other attributes.
 */
class Park : public Landmark {
public:
    Park();
    Park(std::string address, std::string nameOfPark, std::string date, int condition);
    
    /**
     * @brief Calculates the building cost of the park.
     * @return The build cost as a float.
     */
    float getBuildCost();

    /**
     * @brief Retrieves the condition of the park.
     * @return The condition as an integer.
     */
    int getCondition();

    /**
     * @brief Retrieves the address of the park.
     * @return The address as a string.
     */
    std::string getAddress();

    /**
     * @brief Prints the details of the park.
     */
    void print() const override;

    ~Park() = default;

private:
    std::string address;          /**< Address of the park */
    std::string nameOfPark;      /**< Name of the park */
    std::string dateEstablished;  /**< Date when the park was established */
    int condition;                /**< Condition rating of the park */
    float buildingCost;           /**< Construction cost of the park */
};

/**
 * @class Monument
 * @brief Represents a monument landmark.
 *
 * The Monument class encapsulates the details of a monument, including its location,
 * name, establishment date, material used, and condition. It also provides methods
 * to retrieve its build cost and other attributes.
 */
class Monument : public Landmark {
public:
    Monument();
    Monument(std::string location, std::string nameOfMonument, std::string date, std::string material, int condition);
    
    /**
     * @brief Calculates the building cost of the monument.
     * @return The build cost as a float.
     */
    float getBuildCost();

    /**
     * @brief Retrieves the condition of the monument.
     * @return The condition as an integer.
     */
    int getCondition();

    /**
     * @brief Prints the details of the monument.
     */
    void print() const override;

    ~Monument() = default;

private:
    std::string location;          /**< Location of the monument */
    std::string nameOfMonument;    /**< Name of the monument */
    std::string materialUsed;      /**< Material used for the monument */
    std::string dateEstablished;   /**< Date when the monument was established */
    int condition;                 /**< Condition rating of the monument */
    float buildingCost;            /**< Construction cost of the monument */
};

/**
 * @class Center
 * @brief Represents a community center landmark.
 *
 * The Center class encapsulates the details of a community center, including its address,
 * name, establishment date, condition, and description. It also provides methods to retrieve
 * its build cost and other attributes.
 */
class Center : public Landmark {
public:
    Center();
    Center(std::string address, std::string nameOfCenter, std::string date, int condition);
    
    /**
     * @brief Calculates the building cost of the center.
     * @return The build cost as a float.
     */
    float getBuildCost();

    /**
     * @brief Retrieves the condition of the center.
     * @return The condition as an integer.
     */
    int getCondition();

    /**
     * @brief Prints the details of the center.
     */
    void print() const override;

    ~Center() = default;

private:
    std::string address;          /**< Address of the center */
    std::string nameOfCenter;     /**< Name of the center */
    std::string description;       /**< Description of the center */
    std::string dateEstablished;   /**< Date when the center was established */
    int condition;                 /**< Condition rating of the center */
    float buildingCost;            /**< Construction cost of the center */
};

#endif // LANDMARKS_H

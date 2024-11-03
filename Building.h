#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>

// ABSTRACT PRODUCTS

/**
 * @class Building
 * @brief An abstract base class representing a generic building.
 *
 * This class serves as a base for all building types. It provides an interface
 * for printing building details, which must be implemented by derived classes.
 */
class Building {
public:
    /**
     * @brief Default constructor for the Building class.
     */
    Building() = default;

    /**
     * @brief Default destructor for the Building class.
     */
    virtual ~Building() = default;

    /**
     * @brief Pure virtual function to print building details.
     *
     * This function must be implemented by derived classes to provide
     * specific details about the building.
     */
    virtual void print() const = 0;
};

/**
 * @class ResidentialBuilding
 * @brief An abstract class representing a residential building.
 *
 * This class is derived from Building and can be further extended
 * for specific types of residential buildings.
 */
class ResidentialBuilding : public Building {
public:
    /**
     * @brief Default destructor for the ResidentialBuilding class.
     */
    virtual ~ResidentialBuilding() = default;
};

/**
 * @class CommercialBuilding
 * @brief An abstract class representing a commercial building.
 *
 * This class is derived from Building and provides additional functionality
 * specific to commercial buildings.
 */
class CommercialBuilding : public Building {
public:
    /**
     * @brief Default destructor for the CommercialBuilding class.
     */
    virtual ~CommercialBuilding() = default;

    /**
     * @brief Gets the construction cost of the building.
     * @return The build cost as a float.
     */
    virtual float getBuildCost() const = 0;

    /**
     * @brief Gets the address of the building.
     * @return The address as a string.
     */
    virtual std::string getAddress() const = 0;

    /**
     * @brief Prints the details of the commercial building.
     *
     * This function must be implemented by derived classes to provide
     * specific details about the commercial building.
     */
    virtual void print() const = 0;
};

/**
 * @class IndustrialBuilding
 * @brief An abstract class representing an industrial building.
 *
 * This class is derived from Building and defines operations specific to
 * industrial buildings, such as production and worker management.
 */
class IndustrialBuilding : public Building {
public:
    /**
     * @brief Default destructor for the IndustrialBuilding class.
     */
    virtual ~IndustrialBuilding() = default;

    /**
     * @brief Constructs the industrial building.
     */
    virtual void construct() = 0;

    /**
     * @brief Maintains the industrial building.
     */
    virtual void maintain() = 0;

    /**
     * @brief Starts production in the industrial building.
     */
    virtual void startProduction() = 0;

    /**
     * @brief Stops production in the industrial building.
     */
    virtual void stopProduction() = 0;

    /**
     * @brief Hires a worker for the industrial building.
     * @param workerName The name of the worker to be hired.
     */
    virtual void hireWorker(const std::string& workerName) = 0;

    /**
     * @brief Allocates jobs within the industrial building.
     */
    virtual void allocateJobs() = 0;

    /**
     * @brief Gets the number of workers in the industrial building.
     * @return The number of workers as an integer.
     */
    virtual int getNumberOfWorkers() const = 0;

    /**
     * @brief Prints the details of the industrial building.
     *
     * This function must be implemented by derived classes to provide
     * specific details about the industrial building.
     */
    virtual void print() const = 0;
};

/**
 * @class Landmark
 * @brief An abstract class representing a landmark building.
 *
 * This class is derived from Building and can be further extended
 * for specific types of landmark buildings.
 */
class Landmark : public Building {
public:
    /**
     * @brief Default destructor for the Landmark class.
     */
    virtual ~Landmark() = default;
};

#endif // BUILDING_H

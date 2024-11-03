// Factories.h
#ifndef FACTORIES_H
#define FACTORIES_H

#include <vector>
#include <iostream>
#include "Building.h"
#include "MaterialHub.h"

/**
 * @class Factories
 * @brief Represents a factory in the industrial building category.
 *
 * The Factories class inherits from IndustrialBuilding and manages 
 * factory-specific operations such as production, maintenance, 
 * and worker management.
 */
class Factories : public IndustrialBuilding {
private:
    MaterialHub* materialHub; ///< Pointer to the material hub used for supplies.
    std::vector<MaterialHub*> materials; ///< List of materials available in the factory.
    std::string factoryName; ///< Name of the factory.
    std::vector<std::string> workers; ///< List of workers employed at the factory.
    bool isOperational; ///< Status of the factory's operational state.
    bool productionStatus; ///< Current production status of the factory.
    int maintenanceCount; ///< Count of maintenance operations performed.
    int numberOfWorkers; ///< Total number of workers employed.

public:
    /**
     * @brief Constructs a Factories object.
     *
     * @param hub Pointer to the MaterialHub to be used.
     * @param name Name of the factory (default is "Default Factory").
     */
    explicit Factories(MaterialHub* hub, const std::string& name = "Default Factory");

    /**
     * @brief Destroys the Factories object.
     */
    ~Factories();

    /**
     * @brief Constructs the factory.
     *
     * This method implements the construction logic for the factory.
     */
    void construct() override;

    /**
     * @brief Performs maintenance on the factory.
     *
     * This method implements the maintenance logic for the factory.
     */
    void maintain() override;

    /**
     * @brief Starts production in the factory.
     *
     * This method changes the production status to active.
     */
    void startProduction() override;

    /**
     * @brief Stops production in the factory.
     *
     * This method changes the production status to inactive.
     */
    void stopProduction() override;

    /**
     * @brief Hires a new worker.
     *
     * @param workerName The name of the worker to be hired.
     */
    void hireWorker(const std::string& workerName) override;

    /**
     * @brief Allocates jobs to workers.
     *
     * This method implements the logic for job allocation to workers.
     */
    void allocateJobs() override;

    /**
     * @brief Gets the number of workers in the factory.
     *
     * @return The total number of workers.
     */
    int getNumberOfWorkers() const override;

    /**
     * @brief Prints factory details.
     *
     * This method provides a description of the factory's current state.
     */
    void print() const override;

    /**
     * @brief Checks if the factory is operational.
     *
     * @return True if the factory is operational, false otherwise.
     */
    bool isFactoryOperational() const;

    /**
     * @brief Gets the maintenance count.
     *
     * @return The number of maintenance operations performed.
     */
    int getMaintenanceCount() const;
};

#endif // FACTORIES_H

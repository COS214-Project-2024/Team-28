#ifndef WAREHOUSES_H
#define WAREHOUSES_H

#include <vector>
#include <string>
#include "Building.h"

/**
 * @class Warehouses
 * @brief Represents a warehouse in an industrial setting.
 *
 * The Warehouses class is derived from the IndustrialBuilding class and 
 * encapsulates properties and methods related to warehouse operations, 
 * such as managing inventory, workers, and production.
 */
class Warehouses : public IndustrialBuilding {
private:
    std::string warehouseName;       ///< Name of the warehouse
    std::vector<std::string> workers;///< List of workers in the warehouse
    std::vector<std::string> inventory;///< Current inventory of the warehouse
    bool isOperational;              ///< Operational status of the warehouse
    bool productionStatus;           ///< Current production status (running or stopped)
    int maintenanceCount;            ///< Count of maintenance activities performed
    int numberOfWorkers;             ///< Current number of workers employed

public:
    /**
     * @brief Constructs a Warehouses object with a given name.
     * @param name The name of the warehouse, default is "Default Warehouse".
     */
    explicit Warehouses(const std::string& name = "Default Warehouse");

    /**
     * @brief Constructs the warehouse.
     */
    void construct() override;

    /**
     * @brief Performs maintenance on the warehouse.
     */
    void maintain() override;

    /**
     * @brief Starts production in the warehouse.
     */
    void startProduction() override;

    /**
     * @brief Stops production in the warehouse.
     */
    void stopProduction() override;

    /**
     * @brief Hires a worker for the warehouse.
     * @param workerName The name of the worker to be hired.
     */
    void hireWorker(const std::string& workerName) override;

    /**
     * @brief Allocates jobs to workers in the warehouse.
     */
    void allocateJobs() override;

    /**
     * @brief Gets the current number of workers in the warehouse.
     * @return The number of workers currently employed.
     */
    int getNumberOfWorkers() const override;

    /**
     * @brief Prints details of the warehouse.
     */
    void print() const override;

    /**
     * @brief Adds an item to the warehouse inventory.
     * @param item The item to be added to inventory.
     */
    void addInventory(const std::string& item);

    /**
     * @brief Removes an item from the warehouse inventory.
     * @param item The item to be removed from inventory.
     * @return True if the item was removed successfully, false otherwise.
     */
    bool removeInventory(const std::string& item);
};

#endif // WAREHOUSES_H

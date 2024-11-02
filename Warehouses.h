#ifndef WAREHOUSES_H
#define WAREHOUSES_H

#include <vector>
#include <string>
#include "Building.h"

class Warehouses : public IndustrialBuilding {
private:
    std::string warehouseName;
    std::vector<std::string> workers;
    std::vector<std::string> inventory;
    bool isOperational;
    bool productionStatus;
    int maintenanceCount;
    int numberOfWorkers;

public:
    explicit Warehouses(const std::string& name = "Default Warehouse");

    void construct() override;
    void maintain() override;
    void startProduction() override;
    void stopProduction() override;
    void hireWorker(const std::string& workerName) override;
    void allocateJobs() override;
    int getNumberOfWorkers() const override;
    void print() const override;

    // Warehouse-specific methods
    void addInventory(const std::string& item);
    bool removeInventory(const std::string& item);
};

#endif // WAREHOUSES_H

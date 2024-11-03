#ifndef WAREHOUSES_H
#define WAREHOUSES_H

#include <vector>
#include <string>
#include "IndustrialBuilding.h"

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
    explicit Warehouses(const std::string& name = "Default Warehouse", const std::string& location = "Default Location", int capacity = 100);

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

    // Implementing pure virtual functions from IndustrialBuilding
    void startOperation() override;
    void stopOperation() override;
    void performInspection() override;
    std::string getBuildingDetails() const override;
};

#endif // WAREHOUSES_H
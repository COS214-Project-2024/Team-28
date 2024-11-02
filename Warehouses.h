#ifndef WAREHOUSES_H
#define WAREHOUSES_H

#include <vector>
#include <algorithm>
#include <iostream>
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
    explicit Warehouses(const std::string& name = "Default Warehouse") 
        : warehouseName(name)
        , isOperational(false)
        , productionStatus(false)
        , maintenanceCount(0)
        , numberOfWorkers(0) {}

    void construct() override {
        std::cout << "Constructing new warehouse: " << warehouseName << "..." << std::endl;
        std::cout << "Setting up storage areas..." << std::endl;
        std::cout << "Installing inventory management systems..." << std::endl;
        std::cout << "Setting up loading docks..." << std::endl;
        isOperational = true;
        std::cout << "Warehouse construction completed. Status: Operational" << std::endl;
    }

    void maintain() override {
        if (!isOperational) {
            std::cout << "Cannot maintain: Warehouse is not operational" << std::endl;
            return;
        }

        maintenanceCount++;
        std::cout << "\nPerforming warehouse maintenance check #" << maintenanceCount << std::endl;
        std::cout << "1. Checking storage conditions..." << std::endl;
        std::cout << "2. Inspecting security systems..." << std::endl;
        std::cout << "3. Verifying ventilation..." << std::endl;
    }

    void startProduction() override {
        if (!isOperational) {
            std::cout << "Cannot start operations: Warehouse is not operational" << std::endl;
            return;
        }
        productionStatus = true;
        std::cout << "Warehouse operations started at: " << warehouseName << std::endl;
    }

    void stopProduction() override {
        if (productionStatus) {
            productionStatus = false;
            std::cout << "Warehouse operations stopped at: " << warehouseName << std::endl;
        }
    }

    void hireWorker(const std::string& workerName) override {
        workers.push_back(workerName);
        numberOfWorkers++;
        std::cout << "Worker " << workerName << " hired at warehouse: " << warehouseName << std::endl;
    }

    void allocateJobs() override {
        if (!isOperational) {
            std::cout << "Cannot allocate jobs: Warehouse is not operational" << std::endl;
            return;
        }
        std::cout << "Allocating warehouse tasks to workers at: " << warehouseName << std::endl;
        for (const auto& worker : workers) {
            std::cout << "Assigning storage management to: " << worker << std::endl;
        }
    }

    int getNumberOfWorkers() const override {
        return numberOfWorkers;
    }

    void print() const override {
        std::cout << "Warehouse: " << warehouseName 
                 << "\nOperational Status: " << (isOperational ? "Operational" : "Non-operational")
                 << "\nNumber of Workers: " << numberOfWorkers 
                 << "\nOperation Status: " << (productionStatus ? "Active" : "Inactive")
                 << "\nMaintenance Count: " << maintenanceCount 
                 << "\nInventory Items: " << inventory.size() << std::endl;
    }

    // Warehouse-specific methods
    void addInventory(const std::string& item) {
        if (isOperational) {
            inventory.push_back(item);
            std::cout << "Added item to inventory: " << item << std::endl;
        } else {
            std::cout << "Cannot add inventory: Warehouse is not operational" << std::endl;
        }
    }

    bool removeInventory(const std::string& item) {
        if (!isOperational) {
            std::cout << "Cannot remove inventory: Warehouse is not operational" << std::endl;
            return false;
        }

        auto it = std::find(inventory.begin(), inventory.end(), item);
        if (it != inventory.end()) {
            inventory.erase(it);
            std::cout << "Removed item from inventory: " << item << std::endl;
            return true;
        }
        std::cout << "Item not found in inventory: " << item << std::endl;
        return false;
    }
};

#endif // WAREHOUSES_H

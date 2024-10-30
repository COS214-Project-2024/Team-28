#ifndef WAREHOUSES_H
#define WAREHOUSES_H

#include <vector>
#include <iostream>
#include "IndustrialBuilding.h"
#include "Materials.h"

class Warehouses : public IndustrialBuilding {
private:
    std::vector<Steel*> steelStock;
    std::vector<Concrete*> concreteStock;
    std::vector<Wood*> woodStock;
    std::string warehouseLocation;
    std::vector<std::string> workers;
    int capacity;
    bool isReady;
    bool storageStatus;
    int lastInventoryCheck;
    int numberOfWorkers;

public:
    Warehouses(const std::string& location = "Default Location") 
        : capacity(1000), 
          isReady(false), 
          storageStatus(true),
          lastInventoryCheck(0),
          numberOfWorkers(0),
          warehouseLocation(location) {}
    
    ~Warehouses() {
        for (auto* steel : steelStock) delete steel;
        for (auto* concrete : concreteStock) delete concrete;
        for (auto* wood : woodStock) delete wood;
    }

    void construct() override {
        std::cout << "Beginning warehouse construction at " << warehouseLocation << "..." << std::endl;
        
        try {
            std::cout << "Phase 1: Preparing foundation..." << std::endl;
            std::cout << "Phase 2: Erecting support structures..." << std::endl;
            std::cout << "Phase 3: Installing storage systems..." << std::endl;
            
            std::cout << "\nSetting up storage sections:" << std::endl;
            std::cout << "- Steel storage area: Capacity " << capacity/3 << " units" << std::endl;
            std::cout << "- Concrete storage area: Capacity " << capacity/3 << " units" << std::endl;
            std::cout << "- Wood storage area: Capacity " << capacity/3 << " units" << std::endl;
            
            isReady = true;
            std::cout << "\nWarehouse construction completed. Ready for storage operations." << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Warehouse construction failed: " << e.what() << std::endl;
            isReady = false;
        }
    }

    void maintain() override {
        if (!isReady) {
            std::cout << "Cannot maintain: Warehouse is not ready" << std::endl;
            return;
        }

        lastInventoryCheck++;
        std::cout << "\nPerforming warehouse maintenance #" << lastInventoryCheck << std::endl;
        
        std::cout << "Current inventory levels:" << std::endl;
        std::cout << "- Steel: " << steelStock.size() << " units" << std::endl;
        std::cout << "- Concrete: " << concreteStock.size() << " units" << std::endl;
        std::cout << "- Wood: " << woodStock.size() << " units" << std::endl;
        
        int totalItems = steelStock.size() + concreteStock.size() + woodStock.size();
        if (totalItems > capacity * 0.9) {
            std::cout << "\nWARNING: Warehouse at " << (totalItems * 100 / capacity) 
                     << "% capacity. Consider expansion." << std::endl;
        }
    }

    void startProduction() override {
        std::cout << "Warehouses do not support production. Only storage operations are available.\n";
    }

    void stopProduction() override {
        std::cout << "Warehouses do not support production.\n";
    }

    void hireWorker(const std::string& workerName) override {
        workers.push_back(workerName);
        numberOfWorkers++;
        std::cout << "Worker " << workerName << " hired at warehouse: " << warehouseLocation << std::endl;
    }

    void allocateJobs() override {
        if (!isReady) {
            std::cout << "Cannot allocate jobs: Warehouse is not ready" << std::endl;
            return;
        }
        std::cout << "Allocating storage tasks to workers at warehouse: " << warehouseLocation << std::endl;
        for (const auto& worker : workers) {
            std::cout << "Storage task allocated to: " << worker << std::endl;
        }
    }

    int getNumberOfWorkers() const override {
        return numberOfWorkers;
    }

    void print() const override {
        std::cout << "Warehouse: " << warehouseLocation 
                 << "\nOperational Status: " << (isReady ? "Ready" : "Not Ready")
                 << "\nNumber of Workers: " << numberOfWorkers 
                 << "\nStorage Status: " << (storageStatus ? "Active" : "Inactive")
                 << "\nInventory Checks: " << lastInventoryCheck << std::endl;
    }

    bool isWarehouseReady() const { return isReady; }
    int getCurrentCapacity() const { return capacity; }
    int getLastInventoryCheck() const { return lastInventoryCheck; }
};

#endif // WAREHOUSES_H
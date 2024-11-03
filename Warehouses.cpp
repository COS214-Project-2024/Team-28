#include "Warehouses.h"
#include <iostream>
#include <algorithm>

Warehouses::Warehouses(const std::string& name, const std::string& location, int capacity)
    : IndustrialBuilding(name, location, capacity),
      warehouseName(name),
      isOperational(false),
      productionStatus(false),
      maintenanceCount(0),
      numberOfWorkers(0) {}

void Warehouses::construct() {
    std::cout << "Constructing new warehouse: " << warehouseName << "...\n";
    std::cout << "Setting up storage areas...\n";
    std::cout << "Installing inventory management systems...\n";
    std::cout << "Setting up loading docks...\n";
    isOperational = true;
    std::cout << "Warehouse construction completed. Status: Operational\n";
}

void Warehouses::maintain() {
    if (!isOperational) {
        std::cout << "Cannot maintain: Warehouse is not operational\n";
        return;
    }

    maintenanceCount++;
    std::cout << "\nPerforming maintenance check #" << maintenanceCount << std::endl;
    
    std::cout << "1. Checking storage areas..." << std::endl;
    std::cout << "2. Inspecting inventory..." << std::endl;
    std::cout << "3. Verifying safety protocols..." << std::endl;

    bool needsRepair = (maintenanceCount % 3 == 0);
    
    if (needsRepair) {
        std::cout << "Repairs needed! Ordering materials..." << std::endl;
        // Simulate ordering materials
        std::cout << "Repairs completed with new materials" << std::endl;
    }
}

void Warehouses::startProduction() {
    if (!isOperational) {
        std::cout << "Cannot start operations: Warehouse is not operational\n";
        return;
    }
    productionStatus = true;
    std::cout << "Warehouse operations started at: " << warehouseName << "\n";
}

void Warehouses::stopProduction() {
    if (productionStatus) {
        productionStatus = false;
        std::cout << "Warehouse operations stopped at: " << warehouseName << "\n";
    }
}

void Warehouses::hireWorker(const std::string& workerName) {
    workers.push_back(workerName);
    numberOfWorkers++;
    std::cout << "Worker " << workerName << " hired at warehouse: " << warehouseName << std::endl;
}

void Warehouses::allocateJobs() {
    if (!isOperational) {
        std::cout << "Cannot allocate jobs: Warehouse is not operational\n";
        return;
    }
    std::cout << "Allocating warehouse tasks to workers at: " << warehouseName << "\n";
    for (const auto& worker : workers) {
        std::cout << "Assigning storage management to: " << worker << "\n";
    }
}

int Warehouses::getNumberOfWorkers() const {
    return numberOfWorkers;
}

void Warehouses::print() const {
    std::cout << "Warehouse: " << warehouseName 
              << "\nOperational Status: " << (isOperational ? "Operational" : "Non-operational")
              << "\nNumber of Workers: " << numberOfWorkers 
              << "\nOperation Status: " << (productionStatus ? "Active" : "Inactive")
              << "\nMaintenance Count: " << maintenanceCount 
              << "\nInventory Items: " << inventory.size() << "\n";
}

void Warehouses::addInventory(const std::string& item) {
    inventory.push_back(item);
    std::cout << "Added item to inventory: " << item << "\n";
}

bool Warehouses::removeInventory(const std::string& item) {
    auto it = std::find(inventory.begin(), inventory.end(), item);
    if (it != inventory.end()) {
        inventory.erase(it);
        std::cout << "Removed item from inventory: " << item << "\n";
        return true;
    }
    std::cout << "Item not found in inventory: " << item << "\n";
    return false;
}

// Implementing pure virtual functions from IndustrialBuilding
void Warehouses::startOperation() {
    std::cout << "Starting operation at warehouse: " << warehouseName << std::endl;
}

void Warehouses::stopOperation() {
    std::cout << "Stopping operation at warehouse: " << warehouseName << std::endl;
}

void Warehouses::performInspection() {
    std::cout << "Performing inspection at warehouse: " << warehouseName << std::endl;
}

std::string Warehouses::getBuildingDetails() const {
    return "Warehouse Name: " + warehouseName + "\nLocation: " + getLocation() + "\nCapacity: " + std::to_string(getCapacity());
}
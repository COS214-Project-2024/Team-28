#include "Factories.h"
#include <iostream>
#include <exception>

// Constructor
Factories::Factories(MaterialHub* hub, const std::string& name, const std::string& location, int capacity)
    : IndustrialBuilding(name, location, capacity), 
      materialHub(hub), 
      isOperational(false), 
      productionStatus(false),
      maintenanceCount(0),
      numberOfWorkers(0) {}

// Destructor
Factories::~Factories() {
    delete materialHub;
    for (auto* material : materials) {
        delete material;
    }
}

// Construct method
void Factories::construct() {
    std::cout << "Constructing new factory: " << name << "..." << std::endl;

    try {
        Steel* steel = materialHub->createSteel();
        Concrete* concrete = materialHub->createConcrete();
        Wood* wood = materialHub->createWood();

        std::cout << "Basic infrastructure created:" << std::endl;
        std::cout << "- Steel framework installed" << std::endl;
        std::cout << "- Concrete foundation laid" << std::endl;
        std::cout << "- Wood supports added" << std::endl;

        delete steel;
        delete concrete;
        delete wood;

        isOperational = true;
        std::cout << "Factory construction completed. Status: Operational" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Construction failed: " << e.what() << std::endl;
        isOperational = false;
    }
}

// Maintain method
void Factories::maintain() {
    if (!isOperational) {
        std::cout << "Cannot maintain: Factory is not operational" << std::endl;
        return;
    }

    maintenanceCount++;
    std::cout << "\nPerforming maintenance check #" << maintenanceCount << std::endl;
    
    std::cout << "1. Checking machinery..." << std::endl;
    std::cout << "2. Inspecting material storage..." << std::endl;
    std::cout << "3. Verifying safety protocols..." << std::endl;

    bool needsRepair = (maintenanceCount % 3 == 0);
    
    if (needsRepair) {
        std::cout << "Repairs needed! Ordering materials..." << std::endl;
        Steel* repairSteel = materialHub->createSteel();
        delete repairSteel;
        std::cout << "Repairs completed with new materials" << std::endl;
    }
}

// Start production
void Factories::startProduction() {
    if (!productionStatus && isOperational) {
        productionStatus = true;
        std::cout << "Production started at factory: " << name << std::endl;
    } else if (!isOperational) {
        std::cout << "Cannot start production: Factory is not operational" << std::endl;
    }
}

// Stop production
void Factories::stopProduction() {
    if (productionStatus) {
        productionStatus = false;
        std::cout << "Production stopped at factory: " << name << std::endl;
    }
}

// Hire worker
void Factories::hireWorker(const std::string& workerName) {
    workers.push_back(workerName);
    numberOfWorkers++;
    std::cout << "Worker " << workerName << " hired at factory: " << name << std::endl;
}

// Allocate jobs
void Factories::allocateJobs() {
    if (!isOperational) {
        std::cout << "Cannot allocate jobs: Factory is not operational" << std::endl;
        return;
    }
    std::cout << "Allocating jobs to workers at factory: " << name << std::endl;
    for (const auto& worker : workers) {
        std::cout << "Job allocated to: " << worker << std::endl;
    }
}

// Get number of workers
int Factories::getNumberOfWorkers() const {
    return numberOfWorkers;
}

// Print factory status
void Factories::print() const {
    std::cout << "Factory: " << name 
              << "\nOperational Status: " << (isOperational ? "Operational" : "Non-operational")
              << "\nNumber of Workers: " << numberOfWorkers 
              << "\nProduction Status: " << (productionStatus ? "Active" : "Inactive")
              << "\nMaintenance Count: " << maintenanceCount << "\n";
}

// Check if factory is operational
bool Factories::isFactoryOperational() const {
    return isOperational;
}

// Get maintenance count
int Factories::getMaintenanceCount() const {
    return maintenanceCount;
}

// Implementing pure virtual functions from IndustrialBuilding
void Factories::startOperation() {
    std::cout << "Starting operation at factory: " << name << std::endl;
}

void Factories::stopOperation() {
    std::cout << "Stopping operation at factory: " << name << std::endl;
}

void Factories::performInspection() {
    std::cout << "Performing inspection at factory: " << name << std::endl;
}

std::string Factories::getBuildingDetails() const {
    return "Factory Name: " + name + "\nLocation: " + location + "\nCapacity: " + std::to_string(capacity);
}
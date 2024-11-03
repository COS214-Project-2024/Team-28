// IndustrialTests.h
#pragma once
#include <cassert>
#include <iostream>
#include <sstream>
#include "Factories.h"
#include "MaterialHub.h"

class IndustrialTests {
private:
    static void printTestResult(const std::string& testName, bool passed) {
        std::cout << (passed ? "[PASS] " : "[FAIL] ") << testName << std::endl;
    }

    // Basic Factory Tests
    static void testFactoryCreation() {
        MaterialHub* hub = new SteelBuilder();  // Changed from MaterialHub to SteelBuilder
        Factories factory(hub, "Test Factory");
        bool passed = !factory.isFactoryOperational() && 
                     factory.getNumberOfWorkers() == 0 &&
                     factory.getMaintenanceCount() == 0;
        printTestResult("Factory Creation", passed);
    }

    static void testFactoryConstruction() {
        MaterialHub* hub = new SteelBuilder();  // Changed from MaterialHub to SteelBuilder
        Factories factory(hub, "Test Factory");
        factory.construct();
        bool passed = factory.isFactoryOperational();
        printTestResult("Factory Construction", passed);
    }

    // Worker Management Tests
    static void testWorkerManagement() {
        MaterialHub* hub = new SteelBuilder();  // Changed from MaterialHub to SteelBuilder
        Factories factory(hub, "Test Factory");
        factory.construct();
        
        factory.hireWorker("John Doe");
        factory.hireWorker("Jane Smith");
        
        bool passed = factory.getNumberOfWorkers() == 2;
        printTestResult("Worker Management", passed);
    }

    // Production Tests
    static void testProductionCycle() {
        MaterialHub* hub = new SteelBuilder();  // Changed from MaterialHub to SteelBuilder
        Factories factory(hub, "Test Factory");
        
        // Try production before construction
        factory.startProduction();
        bool preConstructionTest = !factory.isFactoryOperational();
        
        factory.construct();
        factory.startProduction();
        bool postConstructionTest = factory.isFactoryOperational();
        
        bool passed = preConstructionTest && postConstructionTest;
        printTestResult("Production Cycle", passed);
    }

    // Maintenance Tests
    static void testMaintenanceTracking() {
        MaterialHub* hub = new SteelBuilder();  // Changed from MaterialHub to SteelBuilder
        Factories factory(hub, "Test Factory");
        
        // Try maintenance before construction
        factory.maintain();
        bool preMaintenanceTest = factory.getMaintenanceCount() == 0;
        
        factory.construct();
        factory.maintain();
        factory.maintain();
        
        bool maintenanceCountTest = factory.getMaintenanceCount() == 2;
        bool passed = preMaintenanceTest && maintenanceCountTest;
        printTestResult("Maintenance Tracking", passed);
    }

    static void testMaintenanceRepair() {
        MaterialHub* hub = new SteelBuilder();  // Changed from MaterialHub to SteelBuilder
        Factories factory(hub, "Test Factory");
        factory.construct();
        
        // Perform three maintenance checks to trigger repair
        factory.maintain();
        factory.maintain();
        factory.maintain();
        
        bool passed = factory.getMaintenanceCount() == 3;
        printTestResult("Maintenance Repair Cycle", passed);
    }

    // Job Allocation Tests
    static void testJobAllocation() {
        MaterialHub* hub = new SteelBuilder();  // Changed from MaterialHub to SteelBuilder
        Factories factory(hub, "Test Factory");
        
        // Test allocation before construction
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
        
        factory.allocateJobs();
        std::string output1 = buffer.str();
        buffer.str("");
        
        // Test allocation after construction
        factory.construct();
        factory.hireWorker("Test Worker");
        factory.allocateJobs();
        std::string output2 = buffer.str();
        
        std::cout.rdbuf(oldCout);
        
        bool passed = output1.find("not operational") != std::string::npos &&
                     output2.find("Allocating jobs") != std::string::npos;
        printTestResult("Job Allocation", passed);
    }

public:
    static void runAllTests() {
        std::cout << "\n=== Running Industrial Building Tests ===\n";
        testFactoryCreation();
        testFactoryConstruction();
        testWorkerManagement();
        testProductionCycle();
        testMaintenanceTracking();
        testMaintenanceRepair();
        testJobAllocation();
    }
};
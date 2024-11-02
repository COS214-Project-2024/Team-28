#include "WastePlantObserver.h"
#include "WastePlant.h"
#include "PowerPlantObserver.h"
#include "PowerPlant.h"
#include "SewagePlantObserver.h"    // Include SewagePlantObserver
#include "SewagePlant.h"            // Include SewagePlant
#include "WaterPlantObserver.h"     // Include WaterPlantObserver
#include "WaterPlant.h"             // Include WaterPlant
#include <memory>
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    // --- WastePlant Testing ---

    // Create a WastePlant
    WastePlant wastePlant("WastePlant1", "Downtown", 1000);

    // Create a WastePlantObserver
    WastePlantObserver wasteManager("WasteManager1");

    // Attach the WastePlant to the WastePlantObserver
    wasteManager.attach(&wastePlant);

    std::cout << "Plant " << wastePlant.getPlantDetails()
              << " attached to manager " << wasteManager.getName() << std::endl;

    std::cout << "\n--- Simulating state changes for WastePlant ---\n" << std::endl;

    // Simulate a state change to Maintenance
    wastePlant.performMaintenance();

    // Simulate a state change to Shutdown after some time
    std::this_thread::sleep_for(std::chrono::seconds(2));
    wastePlant.stopPlant();

    // Simulate a state change back to Operating after some time
    std::this_thread::sleep_for(std::chrono::seconds(2));
    wastePlant.startPlant();

    // Report status for WastePlant
    wasteManager.reportStatus();

    // --- PowerPlant Testing ---

    // Create a PowerPlant
    PowerPlant powerPlant("PowerPlant1", "Uptown", 500.0); // 500 MW capacity

    // Create a PowerPlantObserver
    PowerPlantObserver powerManager("PowerManager1");

    // Attach the PowerPlant to the PowerPlantObserver
    powerManager.attach(&powerPlant);

    std::cout << "\nPlant " << powerPlant.getPlantDetails()
              << " attached to manager " << powerManager.getName() << std::endl;

    std::cout << "\n--- Simulating state changes for PowerPlant ---\n" << std::endl;

    // Simulate initial electricity generation
    powerPlant.changePowerOutput(400.0); // Set initial output to 400 MW
    powerPlant.generateElectricity();

    // Report status for PowerPlant
    powerManager.reportStatus();

    std::cout << "\n--- Simulating Overload ---\n";
    // Simulate increased power demand leading to overload
    powerPlant.changePowerOutput(600.0); // Exceeds capacity to trigger overload
    powerPlant.generateElectricity();

    // Allow time for fault handling
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // Report status after fault handling
    std::cout << "\n--- Reporting Status After Overload Handling ---\n";
    powerManager.reportStatus();

    std::cout << "\n--- Initiating Maintenance ---\n";
    // Simulate maintenance
    powerPlant.performMaintenance();

    // Allow time for maintenance
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // Report final status for PowerPlant
    std::cout << "\n--- Final Reporting Status ---\n";
    powerManager.reportStatus();

    // --- SewagePlant Testing ---

    // Create a SewagePlant
    SewagePlant sewagePlant("SewagePlant1", "Midtown", 800);

    // Create a SewagePlantObserver
    SewagePlantObserver sewageManager("SewageManager1");

    // Attach the SewagePlant to the SewagePlantObserver
    sewageManager.attach(&sewagePlant);

    std::cout << "\nPlant " << sewagePlant.getPlantDetails()
              << " attached to manager " << sewageManager.getName() << std::endl;

    std::cout << "\n--- Simulating state changes for SewagePlant ---\n" << std::endl;

    // Simulate a state change to Maintenance
    sewagePlant.performMaintenance();

    // Simulate a state change to Shutdown after some time
    std::this_thread::sleep_for(std::chrono::seconds(2));
    sewagePlant.stopPlant();

    // Simulate a state change back to Operating after some time
    std::this_thread::sleep_for(std::chrono::seconds(2));
    sewagePlant.startPlant();

    // Report status for SewagePlant
    sewageManager.reportStatus();

    // --- WaterPlant Testing ---

    // Create a WaterPlant
    WaterPlant waterPlant("WaterPlant1", "Riverside", 1200);

    // Create a WaterPlantObserver
    WaterPlantObserver waterManager("WaterManager1");

    // Attach the WaterPlant to the WaterPlantObserver
    waterManager.attach(&waterPlant);

    std::cout << "\nPlant " << waterPlant.getPlantDetails()
              << " attached to manager " << waterManager.getName() << std::endl;

    std::cout << "\n--- Simulating state changes for WaterPlant ---\n" << std::endl;

    // Simulate starting water treatment
    waterPlant.startWaterTreatment();

    // Simulate a state change to Maintenance
    waterPlant.performMaintenance();

    // Simulate a state change to Shutdown after some time
    std::this_thread::sleep_for(std::chrono::seconds(2));
    waterPlant.stopPlant();

    // Simulate a state change back to Operating after some time
    std::this_thread::sleep_for(std::chrono::seconds(2));
    waterPlant.startPlant();

    // Report status for WaterPlant
    waterManager.reportStatus();

    return 0;
}
// main.cpp
#include "WastePlantObserver.h"
#include "WastePlant.h"
#include "PowerPlantObserver.h"
#include "PowerPlant.h"
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

    // Simulate a state change to PartialState
    wastePlant.performMaintenance();

    // Simulate a state change to Shutdown after some time
    std::this_thread::sleep_for(std::chrono::seconds(2));
    wastePlant.stopPlant();

    // Simulate a state change back to Operating after some time
    std::this_thread::sleep_for(std::chrono::seconds(2));
    wastePlant.startPlant();

    // Report status for WastePlant
    wasteManager.reportStatus();

    // // --- PowerPlant Testing ---

    // // Create a PowerPlant
    // PowerPlant powerPlant("PowerPlant1", "Uptown", 500.0); // 500 MW capacity

    // // Create a PowerPlantObserver
    // PowerPlantObserver powerManager("PowerManager1");

    // // Attach the PowerPlant to the PowerPlantObserver
    // powerManager.attach(&powerPlant);

    // std::cout << "\nPlant " << powerPlant.getPlantDetails()
    //           << " attached to manager " << powerManager.getName() << std::endl;

    // std::cout << "\n--- Simulating state changes for PowerPlant ---\n" << std::endl;

    // // Simulate initial electricity generation
    // powerPlant.changePowerOutput(400.0); // Set initial output to 400 MW
    // powerPlant.generateElectricity();

    // // Report status for PowerPlant
    // powerManager.reportStatus();

    // std::cout << "\n--- Simulating Overload ---\n";
    // // Simulate increased power demand leading to overload
    // powerPlant.changePowerOutput(600.0); // Exceeds capacity to trigger overload
    // powerPlant.generateElectricity();

    // // Allow time for fault handling
    // std::this_thread::sleep_for(std::chrono::seconds(3));

    // // Report status after fault handling
    // std::cout << "\n--- Reporting Status After Overload Handling ---\n";
    // powerManager.reportStatus();

    // std::cout << "\n--- Initiating Maintenance ---\n";
    // // Simulate maintenance
    // powerPlant.performMaintenance();

    // // Allow time for maintenance
    // std::this_thread::sleep_for(std::chrono::seconds(3));

    // // Report final status for PowerPlant
    // std::cout << "\n--- Final Reporting Status ---\n";
    // powerManager.reportStatus();

    return 0;
}

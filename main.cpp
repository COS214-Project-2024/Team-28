#include "WastePlantObserver.h"
#include "WastePlant.h"
#include "PowerPlantObserver.h"
#include "PowerPlant.h"
#include "PowerPlantOperationalState.h"
#include "PowerPlantOverloadState.h"
#include "PowerPlantShutdownState.h"
#include "PowerPlant.h"
#include "SewagePlantObserver.h"    
#include "SewagePlant.h"            
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

    // Test sewage handling system
    std::cout << "\n--- Testing Sewage Handling System ---\n" << std::endl;
    sewageManager.handleSewageBlockage("Pipe Blockage");
    sewageManager.initiateFaultHandling("Emergency Overflow");

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


// --- PowerPlant Testing ---

    // Create a PowerPlant instance
    PowerPlant powerPlant("PowerPlant1", "Uptown", 500.0); // 500 MW capacity

    // Create a PowerPlantObserver instance
    PowerPlantObserver powerManager("PowerManager1");

    // Attach the observer to the PowerPlant
    powerManager.attach(&powerPlant);

    std::cout << "Plant " << powerPlant.getPlantDetails()
              << " attached to manager " << powerManager.getName() << std::endl;

    std::cout << "\n--- Simulating Normal Operations for PowerPlant ---\n" << std::endl;

    // Start the PowerPlant
    powerPlant.startPlant(); // Should transition to Operating
    powerPlant.generateElectricity(); // Should generate electricity

    // Report status
    powerManager.reportStatus();

    std::cout << "\n--- Simulating Overload Fault for PowerPlant ---\n";
    // Simulate overload by increasing power output beyond capacity
    powerPlant.changePowerOutput(600.0); // Exceeds capacity, triggers Overload
    powerPlant.generateElectricity(); // Should handle overload

    // Allow time for fault handling
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Report status after handling overload
    std::cout << "\n--- Reporting Status After Overload Handling ---\n";
    powerManager.reportStatus();

    std::cout << "\n--- Initiating Shutdown for PowerPlant ---\n";
    // Stop the PowerPlant, triggering Shutdown
    powerPlant.stopPlant(); // Should transition to Shutdown
    powerPlant.generateElectricity(); // Should not generate electricity

 
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Report status after shutdown
    std::cout << "\n--- Reporting Status After Shutdown ---\n";
    powerManager.reportStatus();

    std::cout << "\n--- Attempting Redundant Overload for PowerPlant ---\n";
    powerPlant.changePowerOutput(700.0); 
    powerPlant.generateElectricity();

    // Allow time for any fault handling
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Final status report
    std::cout << "\n--- Final Reporting Status for PowerPlant ---\n";
    powerManager.reportStatus();

    return 0;
}
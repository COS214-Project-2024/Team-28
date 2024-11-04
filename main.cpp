// #include <iostream>
// #include <vector>
// #include "BuildingFactory.h"
// #include "LandMarkFactory.h"
// #include "CommercialBuildingFactory.h"
// #include "ResidentialBuildingFactory.h"
// #include "IndustrialFactory.h"
// #include "MaterialHub.h"
// #include "Government.h"
// #include "CityManager.h"
// #include "PayTaxes.h"
// #include "PayLevies.h"
// #include "EconomicGrowthStrategy.h"
// #include "SocialWelfareStrategy.h"
// #include "HighPopulationStrategy.h"
// #include "Citizen.h"
// #include "Worker.h"
// #include "Dependent.h"
// #include "HealthServices.h"
// #include "EducationServices.h"
// #include "EntertainmentServices.h"
// #include "SecurityServices.h"
// #include "TransportationServices.h"
// #include "PublicTransit.h"
// #include "Trains.h"
// #include "Airports.h"
// #include "Roads.h"
// #include "IndustrialBuilding.h"
// #include "WastePlantObserver.h"
// #include "WastePlant.h"
// #include "PowerPlantObserver.h"
// #include "PowerPlant.h"
// #include "PowerPlantOperationalState.h"
// #include "PowerPlantOverloadState.h"
// #include "PowerPlantShutdownState.h"
// #include "PowerPlant.h"
// #include "SewagePlantObserver.h"    
// #include "SewagePlant.h"            
// #include "WaterPlantObserver.h"     // Include WaterPlantObserver
// #include "WaterPlant.h"             // Include WaterPlant
// #include <memory>
// #include <iostream>
// #include <thread>
// #include <chrono>

// void printCitizenSatisfaction(const std::vector<Citizen>& citizens) {
//     for (const auto& citizen : citizens) {
//         std::cout << "Citizen satisfaction: " << citizen.getSatisfaction() << std::endl;
//     }
// }
// void printSectionHeader(const std::string& section) {
//     std::cout << "\n/*----------------------- " << section << " -----------------------*/\n";
// }

// void testMallOperations(Mall* mall) {
//     // Test adding shops
//     try {
//         std::cout << "\nTesting shop management...\n";
//         MallShop shop1("Fashion Store", "Clothing", 100.0, 5000.0);
//         MallShop shop2("Food Court", "Restaurant", 200.0, 8000.0);
//         MallShop shop3("Electronics", "Technology", 150.0, 7000.0);
        
//         mall->addShop(shop1);
//         std::cout << "Added Fashion Store\n";
//         mall->addShop(shop2);
//         std::cout << "Added Food Court\n";
//         mall->addShop(shop3);
//         std::cout << "Added Electronics Store\n";
        
//         // Set some example revenues for tax calculation demonstration
//         shop1.setRevenue(50000.0);
//         shop1.setOperatingCosts(30000.0);
//         shop2.setRevenue(75000.0);
//         shop2.setOperatingCosts(45000.0);
//         shop3.setRevenue(60000.0);
//         shop3.setOperatingCosts(35000.0);
        
//     } catch (const std::runtime_error& e) {
//         std::cout << "Error adding shops: " << e.what() << std::endl;
//     }

//     mall->printShops();

//     // Test visitor management
//     std::cout << "\nTesting visitor management...\n";
//     if (mall->admitVisitors(500)) {
//         std::cout << "Successfully admitted 500 visitors\n";
//     } else {
//         std::cout << "Cannot admit 500 visitors - over capacity\n";
//     }
    
//     // Try admitting more visitors than capacity
//     if (mall->admitVisitors(2000)) {
//         std::cout << "Successfully admitted 2000 more visitors\n";
//     } else {
//         std::cout << "Prevented overcrowding: Cannot admit 2000 more visitors\n";
//     }

//     // Test emergency system
//     std::cout << "\nTesting emergency system...\n";
//     mall->triggerEmergencyEvacuation();
//     std::cout << "Emergency evacuation triggered - all visitors evacuated\n";

//     // Test maintenance scheduling
//     std::cout << "\nTesting maintenance scheduling...\n";
//     std::time_t now = std::time(nullptr);
//     mall->scheduleRoutineMaintenance("Food Court", now); // Schedule for tomorrow
//     mall->scheduleRoutineMaintenance("Parking Area", now); // Schedule for day after tomorrow
//     std::cout << "Maintenance tasks scheduled\n";

//     // Calculate and display taxes
//     std::cout << "\nTesting financial calculations...\n";
//     double taxes = mall->calculateMonthlyTaxes();
//     std::cout << "Monthly taxes due: $" << taxes << std::endl;

//     // Print final state
//     std::cout << "\nFinal mall state:\n";
//     mall->print();
// }


// int main() {
//     CityManager cityManager;
//     Government government;
//     PayTaxes payTaxes(&cityManager);
//     PayLevies payLevies(&cityManager);
//     EconomicGrowthStrategy economicGrowthStrategy;
//     SocialWelfareStrategy socialWelfareStrategy;
//     HighPopulationStrategy highPopulationStrategy;
// /*-----------------------PARKS-----------------------*/
//     LandMarkFactory landmarkFactory;
//     //Landmark* park = landmarkFactory.createPark();
//     //might need to delete default contructor
//     Park* p = new Park("123 Park Ave", "Central Park", "1858", 5);
//     p->print();

//     // Landmark* monument = landmarkFactory.createMonument();
//     Monument* m = new Monument("456 Monument St", "Liberty Bell", "1753", "Bronze", 4);
//     m->print();

//     // Landmark* center = landmarkFactory.createCenters();
//     Center* c = new Center("789 Center Rd", "Community Center", "2000", 3);
//     c->print();

//     // Clean up
//     delete p;
//     delete m;
//     delete c;
//     /*---------------------------------------------------*/

//     /*-----------------------RESIDENTIAL-----------------------*/
//     ResidentialBuildingFactory residentialFactory;
//     House* newHouse = new House("somewhere", 18);
//     newHouse->print();
//     newHouse->getBuildCost();

//     Flat* newFlat = new Flat("nowhere", 100);
//     newFlat->print();

//     TownHouse* newTH = new TownHouse("up", 4);
//     newTH->print();

//     Estate* newEstate = new Estate("down", 10, 25);
//     newEstate->avergeResidentsPerUnit();
//     /*---------------------------------------------------*/

//     /*-----------------------COMMERCIAL-----------------------*/
//     // CommercialBuildingFactory cF;
//     // Shop* newShop = new Shop("bikini-bottom", "KrabbyPatty", "Resturant", 1);
//     // newShop->print();

//     // Office* newOffice = new Office("184 drive", "EASPORTS", "GAMING", 1);
//     // newOffice->print();

//     // Mall* newMall = new Mall("Midrand", "Mall of Africa ", 300);
//     // newMall->print();

//     CommercialBuildingFactory cF;
//     Shop* newShop = new Shop("bikini-bottom", "KrabbyPatty", "Restaurant", 1);
//     newShop->print();
//     Office* newOffice = new Office("184 drive", "EASPORTS", "GAMING", 1);
//     newOffice->print();


//     printSectionHeader("MALL SIMULATION");
    
//     // Create a new mall with specific parameters
//     Mall* newMall = new Mall("Midrand", "Mall of Africa", 2000); // 2000 person capacity
    
//     // Run mall operations test
//     testMallOperations(newMall);
//     std::cout<<"==================================MALL DONE===========================================";
//     /*---------------------------------------------------*/

//     printSectionHeader("INDUSTRIAL");
    
//     IndustrialFactory industrialFactory;
    
//     std::cout << "\n=== Testing Factory Creation and Basic Operations ===\n";
//     IndustrialBuilding* steelFactory = industrialFactory.createFactory();
    
//     // Test construction
//     steelFactory->construct();
    
//     // Test worker management
//     steelFactory->hireWorker("John Smith");
//     steelFactory->hireWorker("Jane Doe");
//     steelFactory->hireWorker("Bob Wilson");
//     steelFactory->allocateJobs();
    
//     // Test production cycle
//     steelFactory->startProduction();
//     steelFactory->maintain();
//     steelFactory->maintain();  // Second maintenance check
//     steelFactory->maintain();  // Third maintenance check - should trigger repairs
//     steelFactory->stopProduction();
    
//     std::cout << "##########################################################################################################################" << std::endl;
//     std::cout << std::endl;
//     std::cout << "\n=== Factory Status ===\n";
//     steelFactory->print();

//     std::cout << "##########################################################################################################################" << std::endl;
//     std::cout << std::endl;
//     std::cout << "\n=== Testing Warehouse Creation and Operations ===\n";
//     IndustrialBuilding* warehouse = industrialFactory.createWarehouse();
    
//     warehouse->construct();
    
//     warehouse->hireWorker("Alice Johnson");
//     warehouse->hireWorker("Charlie Brown");
//     warehouse->allocateJobs();
    
//     warehouse->maintain();
//     warehouse->maintain();
    
//     warehouse->startProduction();
//     warehouse->stopProduction();

//     std::cout << "##########################################################################################################################" << std::endl;
//     std::cout << std::endl;    
//     std::cout << "\n=== Warehouse Status ===\n";
//     warehouse->print();
    
//     std::cout << "\n=== Testing Error Handling ===\n";
//     IndustrialBuilding* newFactory = industrialFactory.createFactory();
//     newFactory->startProduction();  // Should fail because not constructed
//     newFactory->allocateJobs();     // Should fail because not constructed
    
//     // Clean up industrial buildings
//     delete steelFactory;
//     delete warehouse;
//     delete newFactory;
    
//     // Clean up residential buildings
//     delete newHouse;
//     delete newFlat;
//     delete newTH;
//     delete newEstate;
    
//     // Clean up commercial buildings
//     delete newShop;
//     delete newOffice;
//     delete newMall;
//     // Notify citizens
//     std::cout << "##########################################################################################################################" << std::endl;
//     std::cout << std::endl;
//     cityManager.notifyCitizens("Welcome to our city!");
//     std::cout << std::endl;
//     std::cout << "##########################################################################################################################" << std::endl;

//     // Manage services
//     cityManager.manageServices();

//     // Allocate budgets
//     std::cout << "##########################################################################################################################" << std::endl;
//     std::cout << std::endl;
//     cityManager.allocateBudget("Health", 50000.0);
//     cityManager.allocateBudget("Education", 30000.0);
//     cityManager.allocateBudget("Entertainment", 20000.0);
//     cityManager.allocateBudget("Security", 40000.0);
//     cityManager.allocateBudget("Transportation", 60000.0);
//     std::cout << std::endl;
//     std::cout << "##########################################################################################################################" << std::endl;
//     std::cout << std::endl;
//     // Request services
//     cityManager.requestService("Health");
//     cityManager.requestService("Education");
//     cityManager.requestService("Entertainment");
//     cityManager.requestService("Security");
//     cityManager.requestService("Transportation");
//     std::cout << std::endl;

//     // Test HealthServices
//     std::cout << "##########################################################################################################################" << std::endl;
//     std::cout << std::endl;    
//     std::cout << "Testing HealthServices..." << std::endl;
//     HealthServices* healthServices = dynamic_cast<HealthServices*>(cityManager.getService("Health"));
//     if (healthServices) {
//         healthServices->admitPatient("John Doe");
//         healthServices->admitPatient("Jane Doe");
//         healthServices->admitPatient("Alice Smith");
//         healthServices->admitPatient("Bob Johnson");
//         healthServices->admitPatient("Charlie Brown");
//         std::cout << std::endl;
//         std::cout << "##########################################################################################################################" << std::endl;
//         std::cout << std::endl;
//         healthServices->provideTreatment("John Doe");
//         healthServices->provideTreatment("Jane Doe");
//         healthServices->provideTreatment("Alice Smith");
//         healthServices->provideTreatment("Bob Johnson");
//         healthServices->provideTreatment("Charlie Brown");
//     }

//     // Test EducationServices
//     std::cout << std::endl;
//     std::cout << "##########################################################################################################################" << std::endl;
//     std::cout << std::endl;    
//     std::cout << "Testing EducationServices..." << std::endl;
//     EducationServices* educationServices = dynamic_cast<EducationServices*>(cityManager.getService("Education"));
//     if (educationServices) {
//         educationServices->scheduleClass("Math 101");
//         educationServices->scheduleClass("Science 101");
//         educationServices->scheduleClass("History 101");
//         educationServices->scheduleClass("English 101");
//         educationServices->scheduleClass("Art 101");
//         educationServices->recruitTeacher("Jane Smith");
//         educationServices->recruitTeacher("John Smith");
//         educationServices->recruitTeacher("Alice Johnson");
//         educationServices->recruitTeacher("Bob Brown");
//         educationServices->recruitTeacher("Charlie Davis");
//     }

//     // Test EntertainmentServices
//     std::cout << std::endl;
//     std::cout << "##########################################################################################################################" << std::endl;
//     std::cout << std::endl;
//     std::cout << "Testing EntertainmentServices..." << std::endl;
//     EntertainmentServices* entertainmentServices = dynamic_cast<EntertainmentServices*>(cityManager.getService("Entertainment"));
//     if (entertainmentServices) {
//         entertainmentServices->organizeEvent("Music Festival");
//         entertainmentServices->organizeEvent("Movie Night");
//         entertainmentServices->organizeEvent("Art Exhibition");
//         entertainmentServices->cancelEvent("Music Festival");
//         entertainmentServices->cancelEvent("Movie Night");
//         entertainmentServices->cancelEvent("Art Exhibition");
//     }

//     // Test SecurityServices
//     std::cout << std::endl;
//     std::cout << "##########################################################################################################################" << std::endl;
//     std::cout << std::endl;    
//     std::cout << "Testing SecurityServices..." << std::endl;
//     SecurityServices* securityServices = dynamic_cast<SecurityServices*>(cityManager.getService("Security"));
//     if (securityServices) {
//         securityServices->respondToEmergency("City Park");
//         securityServices->respondToEmergency("Main Street");
//         securityServices->respondToEmergency("Central Square");
//         securityServices->conductPatrol();
//     }

//     // Test TransportationServices and its subsystems
//     std::cout << std::endl;
//     std::cout << "##########################################################################################################################" << std::endl;
//     std::cout << std::endl;       
//     std::cout << "Testing TransportationServices and its subsystems..." << std::endl;
//     TransportationServices* transportationServices = dynamic_cast<TransportationServices*>(cityManager.getService("Transportation"));
//     if (transportationServices) {
//         transportationServices->manageSubsystems();
//     }

//     // Test PublicTransit
//     std::cout << std::endl;
//     std::cout << "##########################################################################################################################" << std::endl;
//     std::cout << std::endl;      
//     std::cout << "Testing PublicTransit..." << std::endl;
//     PublicTransit* publicTransit = dynamic_cast<PublicTransit*>(cityManager.getService("PublicTransit"));
//     if (publicTransit) {
//         publicTransit->addVehicle("InterCity");
//         publicTransit->addVehicle("Eagleliner");
//         publicTransit->addVehicle("Greyhound");
//         publicTransit->removeVehicle("InterCity");
//         publicTransit->removeVehicle("Eagleliner");
//         publicTransit->removeVehicle("Greyhound");
//         publicTransit->announceDelay(10);
//     }

//     // Test Trains
//     std::cout << std::endl;
//     std::cout << "##########################################################################################################################" << std::endl;
//     std::cout << std::endl;      
//     std::cout << "Testing Trains..." << std::endl;
//     Trains* trains = dynamic_cast<Trains*>(cityManager.getService("Trains"));
//     if (trains) {
//         trains->addTrain("Express Train");
//         trains->addTrain("Local Train");
//         trains->addTrain("High-Speed Train");
//         trains->removeTrain("Express Train");
//         trains->removeTrain("Local Train");
//         trains->removeTrain("High-Speed Train");
//         trains->scheduleTrain("City Route");
//         trains->scheduleTrain("Suburban Route");
//         trains->scheduleTrain("Intercity Route");
//         trains->announceDelay(5);
//     }

//     // Test Airports
//     std::cout << std::endl;
//     std::cout << "##########################################################################################################################" << std::endl;
//     std::cout << std::endl;      
//     std::cout << "Testing Airports..." << std::endl;
//     Airports* airports = dynamic_cast<Airports*>(cityManager.getService("Airports"));
//     if (airports) {
//         airports->addFlight("Flight 101");
//         airports->addFlight("Flight 102");
//         airports->addFlight("Flight 103");
//         airports->removeFlight("Flight 101");
//         airports->removeFlight("Flight 102");
//         airports->removeFlight("Flight 103");
//         airports->scheduleFlightMaintenance();
//     }

//     // Test Roads
//     std::cout << std::endl;
//     std::cout << "##########################################################################################################################" << std::endl;
//     std::cout << std::endl;      
//     std::cout << "Testing Roads..." << std::endl;
//     Roads* roads = dynamic_cast<Roads*>(cityManager.getService("Roads"));
//     if (roads) {
//         roads->repairRoad();
//         roads->expandLanes(2);
//         roads->regulateTraffic();
//     }

    // // Create some citizens
    // std::vector<Citizen> citizens;
    // citizens.push_back(Worker(&government, true, 50000.0)); // Worker with house
    // citizens.push_back(Worker(&government, false, 60000.0)); // Worker without house
    // citizens.push_back(Dependent(&government, true)); // Dependent with house
    // citizens.push_back(Dependent(&government, false)); // Dependent without house
    // citizens.push_back(Worker(&government, true, 70000.0)); // Worker with house

    // // Set citizens in the government
    // government.setCitizens(citizens);

    // // Apply Economic Growth Strategy
    // std::cout << std::endl;
    // std::cout << "##########################################################################################################################" << std::endl;
    // std::cout << std::endl;      
    // std::cout << "Applying Economic Growth Strategy..." << std::endl;
    // government.setStrategy(&economicGrowthStrategy);
    // government.executeStrategy();
    // printCitizenSatisfaction(citizens);

    // // Apply Social Welfare Strategy
    // std::cout << std::endl;
    // std::cout << "##########################################################################################################################" << std::endl;
    // std::cout << std::endl;      
    // std::cout << "Applying Social Welfare Strategy..." << std::endl;
    // government.setStrategy(&socialWelfareStrategy);
    // government.executeStrategy();
    // printCitizenSatisfaction(citizens);

    // // Citizens acknowledge receiving grants
    // std::cout << "Citizens acknowledge receiving grants:" << std::endl;
    // for (auto& citizen : citizens) {
    //     citizen.acknowledgeGrant();
    // }

    // // Apply High Population Strategy
    // std::cout << std::endl;
    // std::cout << "##########################################################################################################################" << std::endl;
    // std::cout << std::endl;      
    // std::cout << "Applying High Population Strategy..." << std::endl;
    // government.setStrategy(&highPopulationStrategy);
    // government.executeStrategy();
    // printCitizenSatisfaction(citizens);

    // // Collect taxes
    // std::cout << std::endl;
    // std::cout << "##########################################################################################################################" << std::endl;
    // std::cout << std::endl;      
    // std::cout << "Collecting taxes..." << std::endl;
    // government.payTaxes();
    // printCitizenSatisfaction(citizens);

    // // Collect levies
    // std::cout << std::endl;
    // std::cout << "##########################################################################################################################" << std::endl;
    // std::cout << std::endl;      
    // std::cout << "Collecting levies..." << std::endl;
    // cityManager.payLevies(citizens);
    // printCitizenSatisfaction(citizens);

    // // Execute commands
    // std::cout << std::endl;
    // std::cout << "##########################################################################################################################" << std::endl;
    // std::cout << std::endl;      
    // std::cout << "Executing commands..." << std::endl;
    // government.setCommand(&payTaxes);
    // government.executeCommand();
    // printCitizenSatisfaction(citizens);

    // government.setCommand(&payLevies);
    // government.executeCommand();
    // printCitizenSatisfaction(citizens);

    // // Increase taxes and levies
    // std::cout << std::endl;
    // std::cout << "##########################################################################################################################" << std::endl;
    // std::cout << std::endl;      
    // std::cout << "Increasing taxes and levies..." << std::endl;
    // for (int i = 0; i < 1; ++i) {
    //     government.increaseTaxesAndLevies();
    //     for (auto& citizen : citizens) {
    //         citizen.updateSatisfaction();
    //     }
    //     printCitizenSatisfaction(citizens);
    // }

    // // Continuously lower taxes and levies
    // std::cout << std::endl;
    // std::cout << "##########################################################################################################################" << std::endl;
    // std::cout << std::endl;      
    // std::cout << "Continuously lowering taxes and levies..." << std::endl;
    // for (int i = 0; i < 3; ++i) {
    //     government.reduceLevies();
    //     government.setTaxRate(government.getTaxRate() * 0.9);
    //     for (auto& citizen : citizens) {
    //         citizen.updateSatisfaction();
    //     }
    //     printCitizenSatisfaction(citizens);
    // }

    // // Apply Economic Growth Strategy to stabilize levies and taxes
    // std::cout << std::endl;
    // std::cout << "##########################################################################################################################" << std::endl;
    // std::cout << std::endl;      
    // std::cout << "Applying Economic Growth Strategy to stabilize levies and taxes..." << std::endl;
    // government.setStrategy(&economicGrowthStrategy);
    // government.executeStrategy();
    // printCitizenSatisfaction(citizens);

    // std::cout << std::endl;
    // std::cout << "##########################################################################################################################" << std::endl;
    // std::cout << std::endl;  

//         // Create a WastePlant
//     WastePlant wastePlant("WastePlant1", "Downtown", 1000);

//     // Create a WastePlantObserver
//     WastePlantObserver wasteManager("WasteManager1");

//     // Attach the WastePlant to the WastePlantObserver
//     wasteManager.attach(&wastePlant);

//     std::cout << "Plant " << wastePlant.getPlantDetails()
//               << " attached to manager " << wasteManager.getName() << std::endl;

//     std::cout << "\n--- Simulating state changes for WastePlant ---\n" << std::endl;

//     // Simulate a state change to Maintenance
//     wastePlant.performMaintenance();

//     // Simulate a state change to Shutdown after some time
//     std::this_thread::sleep_for(std::chrono::seconds(2));
//     wastePlant.stopPlant();

//     // Simulate a state change back to Operating after some time
//     std::this_thread::sleep_for(std::chrono::seconds(2));
//     wastePlant.startPlant();

//     // Report status for WastePlant
//     wasteManager.reportStatus();

   
//     // --- SewagePlant Testing ---

//     // Create a SewagePlant
//     SewagePlant sewagePlant("SewagePlant1", "Midtown", 800);

//     // Create a SewagePlantObserver
//     SewagePlantObserver sewageManager("SewageManager1");

//     // Attach the SewagePlant to the SewagePlantObserver
//     sewageManager.attach(&sewagePlant);

//     std::cout << "\nPlant " << sewagePlant.getPlantDetails()
//               << " attached to manager " << sewageManager.getName() << std::endl;

//     std::cout << "\n--- Simulating state changes for SewagePlant ---\n" << std::endl;

//     // Simulate a state change to Maintenance
//     sewagePlant.performMaintenance();

//     // Simulate a state change to Shutdown after some time
//     std::this_thread::sleep_for(std::chrono::seconds(2));
//     sewagePlant.stopPlant();

//     // Simulate a state change back to Operating after some time
//     std::this_thread::sleep_for(std::chrono::seconds(2));
//     sewagePlant.startPlant();

//     // Report status for SewagePlant
//     sewageManager.reportStatus();

//     // --- WaterPlant Testing ---

//     // Create a WaterPlant
//     WaterPlant waterPlant("WaterPlant1", "Riverside", 1200);

//     // Create a WaterPlantObserver
//     WaterPlantObserver waterManager("WaterManager1");

//     // Attach the WaterPlant to the WaterPlantObserver
//     waterManager.attach(&waterPlant);

//     std::cout << "\nPlant " << waterPlant.getPlantDetails()
//               << " attached to manager " << waterManager.getName() << std::endl;

//     std::cout << "\n--- Simulating state changes for WaterPlant ---\n" << std::endl;

//     // Simulate starting water treatment
//     waterPlant.startWaterTreatment();

//     // Simulate a state change to Maintenance
//     waterPlant.performMaintenance();

//     // Simulate a state change to Shutdown after some time
//     std::this_thread::sleep_for(std::chrono::seconds(2));
//     waterPlant.stopPlant();

//     // Simulate a state change back to Operating after some time
//     std::this_thread::sleep_for(std::chrono::seconds(2));
//     waterPlant.startPlant();

//     // Report status for WaterPlant
//     waterManager.reportStatus();


// // --- PowerPlant Testing ---

//     // Create a PowerPlant instance
//     PowerPlant powerPlant("PowerPlant1", "Uptown", 500.0); // 500 MW capacity

//     // Create a PowerPlantObserver instance
//     PowerPlantObserver powerManager("PowerManager1");

//     // Attach the observer to the PowerPlant
//     powerManager.attach(&powerPlant);

//     std::cout << "Plant " << powerPlant.getPlantDetails()
//               << " attached to manager " << powerManager.getName() << std::endl;

//     std::cout << "\n--- Simulating Normal Operations for PowerPlant ---\n" << std::endl;

//     // Start the PowerPlant
//     powerPlant.startPlant(); // Should transition to Operating
//     powerPlant.generateElectricity(); // Should generate electricity

//     // Report status
//     powerManager.reportStatus();

//     std::cout << "\n--- Simulating Overload Fault for PowerPlant ---\n";
//     // Simulate overload by increasing power output beyond capacity
//     powerPlant.changePowerOutput(600.0); // Exceeds capacity, triggers Overload
//     powerPlant.generateElectricity(); // Should handle overload

//     // Allow time for fault handling
//     std::this_thread::sleep_for(std::chrono::seconds(2));

//     // Report status after handling overload
//     std::cout << "\n--- Reporting Status After Overload Handling ---\n";
//     powerManager.reportStatus();

//     std::cout << "\n--- Initiating Shutdown for PowerPlant ---\n";
//     // Stop the PowerPlant, triggering Shutdown
//     powerPlant.stopPlant(); // Should transition to Shutdown
//     powerPlant.generateElectricity(); // Should not generate electricity

//     // Allow time for fault handling
//     std::this_thread::sleep_for(std::chrono::seconds(2));

//     // Report status after shutdown
//     std::cout << "\n--- Reporting Status After Shutdown ---\n";
//     powerManager.reportStatus();

//     std::cout << "\n--- Attempting Redundant Shutdown for PowerPlant ---\n";
//     // Attempt to stop the plant again (should be ignored due to state check)
//     powerPlant.stopPlant();

//     std::cout << "\n--- Attempting Redundant Overload for PowerPlant ---\n";
//     // Attempt to trigger overload again (should be ignored if already in Shutdown)
//     powerPlant.changePowerOutput(700.0); // Attempting to set higher output
//     powerPlant.generateElectricity();

//     // Allow time for any fault handling
//     std::this_thread::sleep_for(std::chrono::seconds(2));

//     // Final status report
//     std::cout << "\n--- Final Reporting Status for PowerPlant ---\n";
//     powerManager.reportStatus();

//     return 0;
// }

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "BuildingFactory.h"
#include "LandMarkFactory.h"
#include "CommercialBuildingFactory.h"
#include "ResidentialBuildingFactory.h"
#include "IndustrialFactory.h"
#include "MaterialHub.h"
#include "Government.h"
#include "CityManager.h"
#include "PayTaxes.h"
#include "PayLevies.h"
#include "EconomicGrowthStrategy.h"
#include "SocialWelfareStrategy.h"
#include "HighPopulationStrategy.h"
#include "Citizen.h"
#include "Worker.h"
#include "Dependent.h"
#include "HealthServices.h"
#include "EducationServices.h"
#include "EntertainmentServices.h"
#include "SecurityServices.h"
#include "TransportationServices.h"
#include "PublicTransit.h"
#include "Trains.h"
#include "Airports.h"
#include "Roads.h"
#include "IndustrialBuilding.h"
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

void printCitizenSatisfaction(const std::vector<Citizen>& citizens);
void printSectionHeader(const std::string& section);
void testMallOperations(Mall* mall); // Forward declaration

void createBuildings(CityManager& cityManager) {
    int buildingChoice;
    std::string address;
    std::cout << "Select a building to create:\n";
    std::cout << "1. Residential Building\n";
    std::cout << "2. Commercial Building\n";
    std::cout << "3. Industrial Building\n";
    std::cout << "4. Landmark\n";
    std::cin >> buildingChoice;

    std::cout << "Enter the address for the building: ";
    std::cin.ignore(); // Clear the newline character from the buffer
    std::getline(std::cin, address);

    switch (buildingChoice) {
        case 1: {
            ResidentialBuildingFactory residentialFactory;
            House* newHouse = new House(address, 18);
            newHouse->print();
            break;
        }
        case 2: {
            CommercialBuildingFactory commercialFactory;
            Mall* newMall = new Mall(address, "Mall of Africa", 2000);
            testMallOperations(newMall);
            break;
        }
        case 3: {
            IndustrialFactory industrialFactory;
            IndustrialBuilding* steelFactory = industrialFactory.createFactory();
            steelFactory->construct();
            steelFactory->hireWorker("John Smith");
            steelFactory->hireWorker("Jane Doe");
            steelFactory->allocateJobs();
            steelFactory->startProduction();
            steelFactory->maintain();
            steelFactory->stopProduction();
            steelFactory->print();
            break;
        }
        case 4: {
            LandMarkFactory landmarkFactory;
            Park* p = new Park(address, "Central Park", "1858", 5);
            p->print();
            break;
        }
        default:
            std::cout << "Invalid choice. Returning to main menu...\n";
            return;
    }
}

void printCitizenSatisfaction(const std::vector<Citizen>& citizens);

void runGovernmentProcesses(Government& government, CityManager& cityManager) {
    EconomicGrowthStrategy economicGrowthStrategy;
    SocialWelfareStrategy socialWelfareStrategy;
    HighPopulationStrategy highPopulationStrategy;

    std::vector<Citizen> citizens = {
        Worker(&government, true, 50000.0),
        Worker(&government, false, 60000.0),
        Dependent(&government, true),
        Dependent(&government, false),
        Worker(&government, true, 70000.0)
    };
    government.setCitizens(citizens);

    bool continueRunning = true;

    while (continueRunning) {
        int choice;
        std::cout << "\nWhat should we do next for the city?\n";
        std::cout << "1. Increase Taxes and Levies (Citizens might not be happy!)\n";
        std::cout << "2. Reduce Taxes and Levies (Give the people some relief!)\n";
        std::cout << "3. Set Strategy (Choose a long-term plan)\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int increaseLevels;
                std::cout << "\nHow many levels would you like to increase taxes and levies? ";
                std::cin >> increaseLevels;

                for (int i = 0; i < increaseLevels; ++i) {
                    std::cout << "\nIncreasing taxes and levies... The citizens are grumbling louder!\n";
                    government.increaseTaxesAndLevies();
                    for (auto& citizen : citizens) {
                        citizen.updateSatisfaction();  // Automatically handles strike conditions
                    }
                    printCitizenSatisfaction(citizens);

                    // Check if any citizen is striking
                    bool anyStriking = false;
                    for (const auto& citizen : citizens) {
                        if (citizen.isStriking()) {
                            anyStriking = true;
                            break;
                        }
                    }

                    if (anyStriking) {
                        std::cout << "\nCitizens are on strike! Immediate action is required to pacify them.\n";
                        break;
                    }
                }
                break;
            }
            case 2: {
                int decreaseLevels;
                std::cout << "\nHow many levels would you like to lower taxes and levies? ";
                std::cin >> decreaseLevels;

                for (int i = 0; i < decreaseLevels; ++i) {
                    std::cout << "\nReducing taxes and levies... Citizens are starting to calm down.\n";
                    government.reduceLevies();
                    government.setTaxRate(government.getTaxRate() * 0.9);
                    for (auto& citizen : citizens) {
                        citizen.updateSatisfaction();  // Automatically handles stop striking
                    }
                    printCitizenSatisfaction(citizens);

                    // Check if all citizens have stopped striking
                    bool allCalm = true;
                    for (const auto& citizen : citizens) {
                        if (citizen.isStriking()) {
                            allCalm = false;
                            break;
                        }
                    }

                    if (allCalm) {
                        std::cout << "\nCitizen satisfaction has improved, and stability is returning to the city.\n";
                        break;
                    }
                }
                break;
            }
            case 3: {
                int strategyChoice;
                std::cout << "\nChoose a strategy to shape the future:\n";
                std::cout << "1. Economic Growth Strategy (Focus on prosperity)\n";
                std::cout << "2. Social Welfare Strategy (Support for all citizens)\n";
                std::cout << "3. High Population Strategy (Plan for the future population boom)\n";
                std::cout << "Enter your choice: ";
                std::cin >> strategyChoice;

                switch (strategyChoice) {
                    case 1:
                        std::cout << "\nApplying the Economic Growth Strategy... Citizens hope for economic opportunities!\n";
                        government.setStrategy(&economicGrowthStrategy);
                        for (auto& citizen : citizens) {
                        citizen.setSatisfaction(50);  // Automatically handles stop striking
                    }
                        break;
                    case 2:
                        std::cout << "\nApplying the Social Welfare Strategy... Citizens feel more supported and cared for.\n";
                        government.setStrategy(&socialWelfareStrategy);
                        break;
                    case 3:
                        std::cout << "\nApplying the High Population Strategy... Citizens are ready for future growth.\n";
                        government.setStrategy(&highPopulationStrategy);
                        break;
                    default:
                        std::cout << "Invalid choice. Returning to main menu...\n";
                        continue;
                }
                government.executeStrategy();
                printCitizenSatisfaction(citizens);
                break;
            }
            default:
                std::cout << "Invalid choice. Returning to main menu...\n";
                continue;
        }

        char repeat;
        std::cout << "\nWould you like to run another government process? (y/n): ";
        std::cin >> repeat;
        continueRunning = (repeat == 'y' || repeat == 'Y');
    }

    std::cout << "\nThank you for governing with care! The city appreciates your efforts.\n";
}

void runCitizenRequests(CityManager& cityManager) {
    bool continueRequesting = true;

    while (continueRequesting) {
        int serviceChoice;
        std::cout << "\nSelect a service to request:\n";
        std::cout << "1. Health Services\n";
        std::cout << "2. Education Services\n";
        std::cout << "3. Entertainment Services\n";
        std::cout << "4. Security Services\n";
        std::cout << "5. Transportation Services\n";
        std::cout << "Enter your choice: ";
        std::cin >> serviceChoice;

        switch (serviceChoice) {
            case 1: {
                HealthServices* healthServices = dynamic_cast<HealthServices*>(cityManager.getService("Health"));
                if (healthServices) {
                    std::string patientName;
                    std::cout << "Enter patient name: ";
                    std::cin.ignore();
                    std::getline(std::cin, patientName);
                    healthServices->admitPatient(patientName);
                    healthServices->provideTreatment(patientName);
                }
                break;
            }
            case 2: {
                EducationServices* educationServices = dynamic_cast<EducationServices*>(cityManager.getService("Education"));
                if (educationServices) {
                    std::string className;
                    std::cout << "Enter class name: ";
                    std::cin.ignore();
                    std::getline(std::cin, className);
                    educationServices->scheduleClass(className);
                }
                break;
            }
            case 3: {
                EntertainmentServices* entertainmentServices = dynamic_cast<EntertainmentServices*>(cityManager.getService("Entertainment"));
                if (entertainmentServices) {
                    std::string eventName;
                    std::cout << "Enter event name: ";
                    std::cin.ignore();
                    std::getline(std::cin, eventName);
                    entertainmentServices->organizeEvent(eventName);
                }
                break;
            }
            case 4: {
                SecurityServices* securityServices = dynamic_cast<SecurityServices*>(cityManager.getService("Security"));
                if (securityServices) {
                    std::string location;
                    std::cout << "Enter location for emergency response: ";
                    std::cin.ignore();
                    std::getline(std::cin, location);
                    securityServices->respondToEmergency(location);
                }
                break;
            }
            case 5: {
                TransportationServices* transportationServices = dynamic_cast<TransportationServices*>(cityManager.getService("Transportation"));
                if (transportationServices) {
                    int transportChoice;
                    std::cout << "Select a transportation option:\n";
                    std::cout << "1. Roads\n";
                    std::cout << "2. Public Transit\n";
                    std::cout << "3. Trains\n";
                    std::cout << "4. Airports\n";
                    std::cin >> transportChoice;

                    switch (transportChoice) {
                        case 1: {
                            Roads* roads = dynamic_cast<Roads*>(cityManager.getService("Roads"));
                            if (roads) {
                                int roadChoice;
                                std::cout << "Select a road operation:\n";
                                std::cout << "1. Repair Road\n";
                                std::cout << "2. Expand Lanes\n";
                                std::cin >> roadChoice;

                                switch (roadChoice) {
                                    case 1:
                                        roads->repairRoad();
                                        break;
                                    case 2:
                                        int lanes;
                                        std::cout << "Enter number of lanes to expand: ";
                                        std::cin >> lanes;
                                        roads->expandLanes(lanes);
                                        break;
                                    default:
                                        std::cout << "Invalid choice. Returning to transportation menu...\n";
                                        break;
                                }
                            }
                            break;
                        }
                        case 2: {
                            PublicTransit* publicTransit = dynamic_cast<PublicTransit*>(cityManager.getService("PublicTransit"));
                            if (publicTransit) {
                                int transitChoice;
                                std::cout << "Select a public transit operation:\n";
                                std::cout << "1. Add Vehicle\n";
                                std::cout << "2. Announce Delay\n";
                                std::cin >> transitChoice;

                                switch (transitChoice) {
                                    case 1: {
                                        std::string vehicleName;
                                        std::cout << "Enter vehicle name: ";
                                        std::cin.ignore();
                                        std::getline(std::cin, vehicleName);
                                        publicTransit->addVehicle(vehicleName);
                                        break;
                                    }
                                    case 2: {
                                        int delay;
                                        std::cout << "Enter delay in minutes: ";
                                        std::cin >> delay;
                                        publicTransit->announceDelay(delay);
                                        break;
                                    }
                                    default:
                                        std::cout << "Invalid choice. Returning to transportation menu...\n";
                                        break;
                                }
                            }
                            break;
                        }
                        case 3: {
                            Trains* trains = dynamic_cast<Trains*>(cityManager.getService("Trains"));
                            if (trains) {
                                int trainChoice;
                                std::cout << "Select a train operation:\n";
                                std::cout << "1. Add Train\n";
                                std::cout << "2. Schedule Train\n";
                                std::cin >> trainChoice;

                                switch (trainChoice) {
                                    case 1: {
                                        std::string trainName;
                                        std::cout << "Enter train name: ";
                                        std::cin.ignore();
                                        std::getline(std::cin, trainName);
                                        trains->addTrain(trainName);
                                        break;
                                    }
                                    case 2: {
                                        std::string routeName;
                                        std::cout << "Enter route name: ";
                                        std::cin.ignore();
                                        std::getline(std::cin, routeName);
                                        trains->scheduleTrain(routeName);
                                        break;
                                    }
                                    default:
                                        std::cout << "Invalid choice. Returning to transportation menu...\n";
                                        break;
                                }
                            }
                            break;
                        }
                        case 4: {
                            Airports* airports = dynamic_cast<Airports*>(cityManager.getService("Airports"));
                            if (airports) {
                                int airportChoice;
                                std::cout << "Select an airport operation:\n";
                                std::cout << "1. Add Flight\n";
                                std::cout << "2. Schedule Flight Maintenance\n";
                                std::cin >> airportChoice;

                                switch (airportChoice) {
                                    case 1: {
                                        std::string flightName;
                                        std::cout << "Enter flight name: ";
                                        std::cin.ignore();
                                        std::getline(std::cin, flightName);
                                        airports->addFlight(flightName);
                                        break;
                                    }
                                    case 2:
                                        airports->scheduleFlightMaintenance();
                                        break;
                                    default:
                                        std::cout << "Invalid choice. Returning to transportation menu...\n";
                                        break;
                                }
                            }
                            break;
                        }
                        default:
                            std::cout << "Invalid choice. Returning to main menu...\n";
                            break;
                    }
                }
                break;
            }
            default:
                std::cout << "Invalid choice. Returning to main menu...\n";
                return;
        }

        char repeat;
        std::cout << "\nWould you like to request another service? (y/n): ";
        std::cin >> repeat;
        continueRequesting = (repeat == 'y' || repeat == 'Y');
    }

    std::cout << "\nReturning to the main menu...\n";
}
#include <iostream>
#include <string>

void manageCityPlants() {
    bool allPlantsCreated = false;

    // Plant and manager declarations
    WastePlant* wastePlant = nullptr;
    SewagePlant* sewagePlant = nullptr;
    WaterPlant* waterPlant = nullptr;
    PowerPlant* powerPlant = nullptr;

    WastePlantObserver* wasteManager = nullptr;
    SewagePlantObserver* sewageManager = nullptr;
    WaterPlantObserver* waterManager = nullptr;
    PowerPlantObserver* powerManager = nullptr;

    bool continueManaging = true;

    while (!allPlantsCreated) {
        int createChoice;
        std::cout << "\nWould you like to:\n";
        std::cout << "1. Create a specific plant\n";
        std::cout << "2. Create all plants at once\n";
        std::cout << "0. Back to main menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> createChoice;

        if (createChoice == 0) {
            std::cout << "Returning to main menu...\n";
            return;
        }

        switch (createChoice) {
            case 1: {
                int plantType;
                std::cout << "\nSelect a plant to create:\n";
                std::cout << "1. WastePlant\n";
                std::cout << "2. SewagePlant\n";
                std::cout << "3. WaterPlant\n";
                std::cout << "4. PowerPlant\n";
                std::cout << "0. Back to plant creation menu\n";
                std::cin >> plantType;

                if (plantType == 0) break;

                switch (plantType) {
                    case 1:
                        if (!wastePlant) {
                            wastePlant = new WastePlant("WastePlant1", "Downtown", 1000);
                            wasteManager = new WastePlantObserver("WasteManager1");
                            wasteManager->attach(wastePlant);
                            std::cout << "WastePlant created and manager attached.\n";
                        } else {
                            std::cout << "WastePlant already created.\n";
                        }
                        break;
                    case 2:
                        if (!sewagePlant) {
                            sewagePlant = new SewagePlant("SewagePlant1", "Midtown", 800);
                            sewageManager = new SewagePlantObserver("SewageManager1");
                            sewageManager->attach(sewagePlant);
                            std::cout << "SewagePlant created and manager attached.\n";
                        } else {
                            std::cout << "SewagePlant already created.\n";
                        }
                        break;
                    case 3:
                        if (!waterPlant) {
                            waterPlant = new WaterPlant("WaterPlant1", "Riverside", 1200);
                            waterManager = new WaterPlantObserver("WaterManager1");
                            waterManager->attach(waterPlant);
                            std::cout << "WaterPlant created and manager attached.\n";
                        } else {
                            std::cout << "WaterPlant already created.\n";
                        }
                        break;
                    case 4:
                        if (!powerPlant) {
                            powerPlant = new PowerPlant("PowerPlant1", "Uptown", 500.0);
                            powerManager = new PowerPlantObserver("PowerManager1");
                            powerManager->attach(powerPlant);
                            std::cout << "PowerPlant created and manager attached.\n";
                        } else {
                            std::cout << "PowerPlant already created.\n";
                        }
                        break;
                    default:
                        std::cout << "Invalid choice.\n";
                        break;
                }
                break;
            }
            case 2:
                if (!wastePlant) {
                    wastePlant = new WastePlant("WastePlant1", "Downtown", 1000);
                    wasteManager = new WastePlantObserver("WasteManager1");
                    wasteManager->attach(wastePlant);
                    std::cout << "WastePlant created and manager attached.\n";
                }
                if (!sewagePlant) {
                    sewagePlant = new SewagePlant("SewagePlant1", "Midtown", 800);
                    sewageManager = new SewagePlantObserver("SewageManager1");
                    sewageManager->attach(sewagePlant);
                    std::cout << "SewagePlant created and manager attached.\n";
                }
                if (!waterPlant) {
                    waterPlant = new WaterPlant("WaterPlant1", "Riverside", 1200);
                    waterManager = new WaterPlantObserver("WaterManager1");
                    waterManager->attach(waterPlant);
                    std::cout << "WaterPlant created and manager attached.\n";
                }
                if (!powerPlant) {
                    powerPlant = new PowerPlant("PowerPlant1", "Uptown", 500.0);
                    powerManager = new PowerPlantObserver("PowerManager1");
                    powerManager->attach(powerPlant);
                    std::cout << "PowerPlant created and manager attached.\n";
                }
                allPlantsCreated = true;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    // Plant management loop
    while (continueManaging) {
        int plantChoice;
        std::cout << "\nSelect a plant to manage:\n";
        std::cout << "1. WastePlant\n";
        std::cout << "2. SewagePlant\n";
        std::cout << "3. WaterPlant\n";
        std::cout << "4. PowerPlant\n";
        std::cout << "0. Back to main menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> plantChoice;

        if (plantChoice == 0) {
            std::cout << "Returning to main menu...\n";
            break;
        }

        int stateChoice;
        std::cout << "Select a state to set:\n";
        std::cout << "1. Start Plant\n";
        std::cout << "2. Stop Plant\n";
        std::cout << "3. Perform Maintenance\n";
        std::cout << "0. Back to plant selection\n";
        std::cin >> stateChoice;

        if (stateChoice == 0) continue;

        switch (plantChoice) {
            case 1:
                if (wastePlant) {
                    switch (stateChoice) {
                        case 1: wastePlant->startPlant(); break;
                        case 2: wastePlant->stopPlant(); break;
                        case 3: wastePlant->performMaintenance(); break;
                        default: std::cout << "Invalid state choice.\n"; break;
                    }
                    wasteManager->reportStatus();
                } else {
                    std::cout << "WastePlant not created.\n";
                }
                break;
            case 2:
                if (sewagePlant) {
                    switch (stateChoice) {
                        case 1: sewagePlant->startPlant(); break;
                        case 2: sewagePlant->stopPlant(); break;
                        case 3: sewagePlant->performMaintenance(); break;
                        default: std::cout << "Invalid state choice.\n"; break;
                    }
                    sewageManager->reportStatus();
                } else {
                    std::cout << "SewagePlant not created.\n";
                }
                break;
            case 3:
                if (waterPlant) {
                    switch (stateChoice) {
                        case 1: waterPlant->startPlant(); break;
                        case 2: waterPlant->stopPlant(); break;
                        case 3: waterPlant->performMaintenance(); break;
                        default: std::cout << "Invalid state choice.\n"; break;
                    }
                    waterManager->reportStatus();
                } else {
                    std::cout << "WaterPlant not created.\n";
                }
                break;
            case 4:
                if (powerPlant) {
                    switch (stateChoice) {
                        case 1: powerPlant->startPlant(); break;
                        case 2: powerPlant->stopPlant(); break;
                        case 3: powerPlant->performMaintenance(); break;
                        default: std::cout << "Invalid state choice.\n"; break;
                    }
                    powerManager->reportStatus();
                } else {
                    std::cout << "PowerPlant not created.\n";
                }
                break;
            default:
                std::cout << "Invalid plant choice.\n";
                break;
        }

        // Prompt to continue managing plants or return to main menu
        char repeat;
        std::cout << "\nWould you like to manage another plant? (y/n): ";
        std::cin >> repeat;
        continueManaging = (repeat == 'y' || repeat == 'Y');
    }

    std::cout << "\nReturning to the main menu...\n";

    // Clean up dynamically allocated memory
    delete wastePlant;
    delete sewagePlant;
    delete waterPlant;
    delete powerPlant;
    delete wasteManager;
    delete sewageManager;
    delete waterManager;
    delete powerManager;
}


void printCitizenSatisfaction(const std::vector<Citizen>& citizens) {
    for (const auto& citizen : citizens) {
        std::cout << "Citizen satisfaction: " << citizen.getSatisfaction() << std::endl;
    }
}

void printSectionHeader(const std::string& section) {
    std::cout << "\n/*----------------------- " << section << " -----------------------*/\n";
}

void testMallOperations(Mall* mall) {
    // Test adding shops
    try {
        std::cout << "\nTesting shop management...\n";
        MallShop shop1("Fashion Store", "Clothing", 100.0, 5000.0);
        MallShop shop2("Food Court", "Restaurant", 200.0, 8000.0);
        MallShop shop3("Electronics", "Technology", 150.0, 7000.0);
        
        mall->addShop(shop1);
        std::cout << "Added Fashion Store\n";
        mall->addShop(shop2);
        std::cout << "Added Food Court\n";
        mall->addShop(shop3);
        std::cout << "Added Electronics Store\n";
        
        // Set some example revenues for tax calculation demonstration
        shop1.setRevenue(50000.0);
        shop1.setOperatingCosts(30000.0);
        shop2.setRevenue(75000.0);
        shop2.setOperatingCosts(45000.0);
        shop3.setRevenue(60000.0);
        shop3.setOperatingCosts(35000.0);
        
    } catch (const std::runtime_error& e) {
        std::cout << "Error adding shops: " << e.what() << std::endl;
    }

    mall->printShops();

    // Test visitor management
    std::cout << "\nTesting visitor management...\n";
    if (mall->admitVisitors(500)) {
        std::cout << "Successfully admitted 500 visitors\n";
    } else {
        std::cout << "Cannot admit 500 visitors - over capacity\n";
    }
    
    // Try admitting more visitors than capacity
    if (mall->admitVisitors(2000)) {
        std::cout << "Successfully admitted 2000 more visitors\n";
    } else {
        std::cout << "Prevented overcrowding: Cannot admit 2000 more visitors\n";
    }

    // Test emergency system
    std::cout << "\nTesting emergency system...\n";
    mall->triggerEmergencyEvacuation();
    std::cout << "Emergency evacuation triggered - all visitors evacuated\n";

    // Test maintenance scheduling
    std::cout << "\nTesting maintenance scheduling...\n";
    std::time_t now = std::time(nullptr);
    mall->scheduleRoutineMaintenance("Food Court", now); // Schedule for tomorrow
    mall->scheduleRoutineMaintenance("Parking Area", now); // Schedule for day after tomorrow
    std::cout << "Maintenance tasks scheduled\n";

    // Calculate and display taxes
    std::cout << "\nTesting financial calculations...\n";
    double taxes = mall->calculateMonthlyTaxes();
    std::cout << "Monthly taxes due: $" << taxes << std::endl;

    // Print final state
    std::cout << "\nFinal mall state:\n";
    mall->print();
}

int main() {
    CityManager cityManager;
    Government government;
    PayTaxes payTaxes(&cityManager);
    PayLevies payLevies(&cityManager);
    EconomicGrowthStrategy economicGrowthStrategy;
    SocialWelfareStrategy socialWelfareStrategy;
    HighPopulationStrategy highPopulationStrategy;

    std::cout << "Welcome to the City Management System!\n";
    std::cout << "Let's start by setting up our city and its citizens.\n";

    // Create a single citizen for testing
    std::vector<Citizen> citizens;
    citizens.push_back(Worker(&government, true, 50000.0)); // Worker with house

    // Set citizens in the government
    government.setCitizens(citizens);

    int mainMenuChoice;
    do {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Create Buildings\n";
        std::cout << "2. Run Government Processes\n";
        std::cout << "3. Run Citizen Requests\n";
        std::cout << "4. Manage City Plants\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> mainMenuChoice;

        switch (mainMenuChoice) {
            case 1:
                createBuildings(cityManager);
                break;
            case 2:
                runGovernmentProcesses(government, cityManager);
                break;
            case 3:
                runCitizenRequests(cityManager);
                break;
            case 4:
                manageCityPlants();
                break;
            case 0:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (mainMenuChoice != 0);

    return 0;
}
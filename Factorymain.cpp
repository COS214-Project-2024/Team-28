// #include <iostream>
// #include "BuildingFactory.h"
// #include "LandMarkFactory.h"
// #include "CommercialBuildingFactory.h"
// #include "ResidentialBuildingFactory.h"
// #include "IndustrialFactory.h"
// #include "MaterialHub.h"


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
//     /*-----------------------PARKS-----------------------*/
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
//     // CommericalBuildingFactory cF;
//     // Shop* newShop = new Shop("bikini-bottom", "KrabbyPatty", "Resturant", 1);
//     // newShop->print();

//     // Office* newOffice = new Office("184 drive", "EASPORTS", "GAMING", 1);
//     // newOffice->print();

//     // Mall* newMall = new Mall("Midrand", "Mall of Africa ", 300);
//     // newMall->print();

//     CommericalBuildingFactory cF;
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
    
//     std::cout << "\n=== Factory Status ===\n";
//     steelFactory->print();
    
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

//     return 0;
// }

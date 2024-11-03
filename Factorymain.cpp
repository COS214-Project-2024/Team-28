#include <iostream>
#include "BuildingFactory.h"
#include "LandMarkFactory.h"
#include "CommercialBuildingFactory.h"
#include "ResidentialBuildingFactory.h"
#include "IndustrialFactory.h"
#include "CommercialTests.h"
#include "IndustrialTests.h"
#include "MaterialHub.h"


void printSectionHeader(const std::string& section) {
    std::cout << "\n/*----------------------- " << section << " -----------------------*/\n";
}

void testMallOperations(Mall* mall) {
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
    mall->scheduleRoutineMaintenance("Food Court", now);
    mall->scheduleRoutineMaintenance("Parking Area", now);
    std::cout << "Maintenance tasks scheduled\n";

    // Calculate and display taxes
    std::cout << "\nTesting financial calculations...\n";
    double taxes = mall->calculateMonthlyTaxes();
    std::cout << "Monthly taxes due: $" << taxes << std::endl;

    // Print final state
    std::cout << "\nFinal mall state:\n";
    mall->print();
}

void testOfficeOperations(Office* office) {
    try {
        std::cout << "\nTesting office unit management...\n";
        OfficeUnit unit1("HR Department", "Human Resources", 150.0, 3000.0);
        OfficeUnit unit2("IT Division", "Technology", 200.0, 4000.0);
        OfficeUnit unit3("Finance", "Accounting", 175.0, 3500.0);
        
        office->addUnit(unit1);
        std::cout << "Added HR Department\n";
        office->addUnit(unit2);
        std::cout << "Added IT Division\n";
        office->addUnit(unit3);
        std::cout << "Added Finance Department\n";
        
        unit1.setRevenue(40000.0);
        unit1.setOperatingCosts(25000.0);
        unit2.setRevenue(60000.0);
        unit2.setOperatingCosts(35000.0);
        unit3.setRevenue(45000.0);
        unit3.setOperatingCosts(28000.0);
        
    } catch (const std::runtime_error& e) {
        std::cout << "Error adding office units: " << e.what() << std::endl;
    }

    office->printUnits();

    std::cout << "\nTesting employee management...\n";
    if (office->admitEmployees(100)) {
        std::cout << "Successfully admitted 100 employees\n";
    } else {
        std::cout << "Cannot admit 100 employees - over capacity\n";
    }
    
    if (office->admitEmployees(1000)) {
        std::cout << "Successfully admitted 1000 more employees\n";
    } else {
        std::cout << "Prevented overcrowding: Cannot admit 1000 more employees\n";
    }

    std::cout << "\nTesting emergency system...\n";
    office->triggerEmergencyEvacuation();
    std::cout << "Emergency evacuation triggered - all employees evacuated\n";

    std::cout << "\nTesting maintenance scheduling...\n";
    std::time_t now = std::time(nullptr);
    office->scheduleRoutineMaintenance("HVAC System", now);
    office->scheduleRoutineMaintenance("Server Room", now);
    std::cout << "Maintenance tasks scheduled\n";

    std::cout << "\nTesting financial calculations...\n";
    double taxes = office->calculateMonthlyTaxes();
    std::cout << "Monthly taxes due: R" << taxes << std::endl;

    // Print final state
    std::cout << "\nFinal office state:\n";
    office->print();
}

void testShopOperations(Shop* shop) {
    // Test adding shop units
    try {
        std::cout << "\nTesting shop unit management...\n";
        ShopUnit unit1("Produce Section", "Groceries", 200.0, 2000.0);
        ShopUnit unit2("Electronics", "Consumer Goods", 150.0, 3000.0);
        ShopUnit unit3("Clothing", "Apparel", 175.0, 2500.0);
        
        shop->addUnit(unit1);
        std::cout << "Added Produce Section\n";
        shop->addUnit(unit2);
        std::cout << "Added Electronics Section\n";
        shop->addUnit(unit3);
        std::cout << "Added Clothing Section\n";
        
        // Set some example revenues for tax calculation demonstration
        unit1.setRevenue(30000.0);
        unit1.setOperatingCosts(20000.0);
        unit2.setRevenue(45000.0);
        unit2.setOperatingCosts(25000.0);
        unit3.setRevenue(35000.0);
        unit3.setOperatingCosts(22000.0);
        
    } catch (const std::runtime_error& e) {
        std::cout << "Error adding shop units: " << e.what() << std::endl;
    }

    shop->printUnits();

    // Test customer management
    std::cout << "\nTesting customer management...\n";
    if (shop->admitCustomers(50)) {
        std::cout << "Successfully admitted 50 customers\n";
    } else {
        std::cout << "Cannot admit 50 customers - over capacity\n";
    }
    
    // Try admitting more customers than capacity
    if (shop->admitCustomers(500)) {
        std::cout << "Successfully admitted 500 more customers\n";
    } else {
        std::cout << "Prevented overcrowding: Cannot admit 500 more customers\n";
    }

    // Test emergency system
    std::cout << "\nTesting emergency system...\n";
    shop->triggerEmergencyEvacuation();
    std::cout << "Emergency evacuation triggered - all customers evacuated\n";

    // Test maintenance scheduling
    std::cout << "\nTesting maintenance scheduling...\n";
    std::time_t now = std::time(nullptr);
    shop->scheduleRoutineMaintenance("Refrigeration Units", now);
    shop->scheduleRoutineMaintenance("Checkout Area", now);
    std::cout << "Maintenance tasks scheduled\n";

    // Calculate and display taxes
    std::cout << "\nTesting financial calculations...\n";
    double taxes = shop->calculateMonthlyTaxes();
    std::cout << "Monthly taxes due: R" << taxes << std::endl;

    // Print final state
    std::cout << "\nFinal shop state:\n";
    shop->print();
}

int main() {
    /*-----------------------PARKS-----------------------*/
    LandMarkFactory landmarkFactory;
    //Landmark* park = landmarkFactory.createPark();
    //might need to delete default contructor
    Park* p = new Park("123 Park Ave", "Central Park", "1858", 5);
    p->print();

    // Landmark* monument = landmarkFactory.createMonument();
    Monument* m = new Monument("456 Monument St", "Liberty Bell", "1753", "Bronze", 4);
    m->print();

    // Landmark* center = landmarkFactory.createCenters();
    Center* c = new Center("789 Center Rd", "Community Center", "2000", 3);
    c->print();

    // Clean up
    delete p;
    delete m;
    delete c;
    /*---------------------------------------------------*/

    /*-----------------------RESIDENTIAL-----------------------*/
    ResidentialBuildingFactory residentialFactory;
    House* newHouse = new House("somewhere", 18);
    newHouse->print();
    newHouse->getBuildCost();

    Flat* newFlat = new Flat("nowhere", 100);
    newFlat->print();

    TownHouse* newTH = new TownHouse("up", 4);
    newTH->print();

    Estate* newEstate = new Estate("down",25);
    newEstate->numberUnits();
    /*---------------------------------------------------*/

    /*-----------------------COMMERCIAL-----------------------*/
    // CommericalBuildingFactory cF;
    printSectionHeader("SHOP SIMULATION");
    Shop* newShop = new Shop("123 Retail St", "SuperMart", 200); // Set max capacity to 200
    testShopOperations(newShop);
    std::cout<<"\t";

    printSectionHeader("OFFICE SIMULATION");
    Office* newOffice = new Office("184 drive", "EASPORTS", 500);
    testOfficeOperations(newOffice);


    printSectionHeader("MALL SIMULATION");
    Mall* newMall = new Mall("Midrand", "Mall of Africa", 2000); // 2000 person capacity
    testMallOperations(newMall);
    std::cout<<"\t";

    printSectionHeader("COMMERCIAL UNIT TESTS");
    CommercialTests::runAllTests();
    std::cout<<"\t";

    printSectionHeader("INDUSTRIAL");
    
    IndustrialFactory industrialFactory;
    
    std::cout << "\n=== Testing Factory Creation and Basic Operations ===\n";
    IndustrialBuilding* steelFactory = industrialFactory.createFactory();
    
    // Test construction
    steelFactory->construct();
    
    // Test worker management
    steelFactory->hireWorker("John Smith");
    steelFactory->hireWorker("Jane Doe");
    steelFactory->hireWorker("Bob Wilson");
    steelFactory->allocateJobs();
    
    // Test production cycle
    steelFactory->startProduction();
    steelFactory->maintain();
    steelFactory->maintain();  // Second maintenance check
    steelFactory->maintain();  // Third maintenance check - should trigger repairs
    steelFactory->stopProduction();
    
    std::cout << "\n=== Factory Status ===\n";
    steelFactory->print();
    
    std::cout << "\n=== Testing Warehouse Creation and Operations ===\n";
    IndustrialBuilding* warehouse = industrialFactory.createWarehouse();
    
    warehouse->construct();
    
    warehouse->hireWorker("Alice Johnson");
    warehouse->hireWorker("Charlie Brown");
    warehouse->allocateJobs();
    
    warehouse->maintain();
    warehouse->maintain();
    
    warehouse->startProduction();
    warehouse->stopProduction();
    
    std::cout << "\n=== Warehouse Status ===\n";
    warehouse->print();
    
    std::cout << "\n=== Testing Error Handling ===\n";
    IndustrialBuilding* newFactory = industrialFactory.createFactory();
    newFactory->startProduction();  // Should fail because not constructed
    newFactory->allocateJobs();     // Should fail because not constructed

    printSectionHeader("INDUSTRIAL UNIT TESTS");
    IndustrialTests::runAllTests();
    
    // Clean up industrial buildings
    delete steelFactory;
    delete warehouse;
    delete newFactory;
    
    // Clean up residential buildings
    delete newHouse;
    delete newFlat;
    delete newTH;
    // delete newEstate;
    
    // Clean up commercial buildings
    delete newShop;
    delete newOffice;
    delete newMall;

    return 0;
}

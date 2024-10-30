#include <iostream>
#include "BuildingFactory.h"
#include "LandMarkFactory.h"
#include "CommercialBuildingFactory.h"
#include "ResidentialBuildingFactory.h"
#include "IndustrialFactory.h"
#include "MaterialHub.h"

void printSectionHeader(const std::string& section) {
    std::cout << "\n/*----------------------- " << section << " -----------------------*/\n";
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

    Estate* newEstate = new Estate("down", 10, 25);
    newEstate->avergeResidentsPerUnit();
    /*---------------------------------------------------*/

    /*-----------------------COMMERCIAL-----------------------*/
    CommericalBuildingFactory cF;
    Shop* newShop = new Shop("bikini-bottom", "KrabbyPatty", "Resturant", 1);
    newShop->print();

    Office* newOffice = new Office("184 drive", "EASPORTS", "GAMING", 1);
    newOffice->print();

    Mall* newMall = new Mall("Midrand", "Mall of Africa ", 300);
    newMall->print();
    /*---------------------------------------------------*/

    printSectionHeader("INDUSTRIAL");
    
    // Create industrial factory
    IndustrialFactory industrialFactory;
    
    // Test Factory Creation and Operations
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
    
    // Print factory status
    std::cout << "\n=== Factory Status ===\n";
    steelFactory->print();
    
    // Test Warehouse Creation and Operations
    std::cout << "\n=== Testing Warehouse Creation and Operations ===\n";
    IndustrialBuilding* warehouse = industrialFactory.createWarehouse();
    
    // Test warehouse construction
    warehouse->construct();
    
    // Test warehouse worker management
    warehouse->hireWorker("Alice Johnson");
    warehouse->hireWorker("Charlie Brown");
    warehouse->allocateJobs();
    
    // Test warehouse maintenance and inventory
    warehouse->maintain();
    warehouse->maintain();
    
    // Test warehouse production methods (should show appropriate messages)
    warehouse->startProduction();
    warehouse->stopProduction();
    
    // Print warehouse status
    std::cout << "\n=== Warehouse Status ===\n";
    warehouse->print();
    
    // Test error handling by trying operations before construction
    std::cout << "\n=== Testing Error Handling ===\n";
    IndustrialBuilding* newFactory = industrialFactory.createFactory();
    newFactory->startProduction();  // Should fail because not constructed
    newFactory->allocateJobs();     // Should fail because not constructed
    
    // Clean up industrial buildings
    delete steelFactory;
    delete warehouse;
    delete newFactory;
    
    // Clean up residential buildings
    delete newHouse;
    delete newFlat;
    delete newTH;
    delete newEstate;
    
    // Clean up commercial buildings
    delete newShop;
    delete newOffice;
    delete newMall;

    return 0;
}
#include "gtest/gtest.h"
#include <iostream>
#include <vector>
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
#include "WaterPlantObserver.h"     
#include "WaterPlant.h"             
#include <memory>
#include <iostream>
#include <thread>
#include <chrono>


void printSectionHeader(const std::string& section) {
    std::cout << "\n/*----------------------- " << section << " -----------------------*/\n";
}

// Test suite for Landmarks
TEST(LandmarkTest, ParkCreation) {
    LandMarkFactory landmarkFactory;
    Park* p = new Park("123 Park Ave", "Central Park", "1858", 5);
    EXPECT_EQ(p->getAddress(), "123 Park Ave");
    delete p;
}

TEST(LandmarkTest, MonumentCreation) {
    LandMarkFactory landmarkFactory;
    Monument* m = new Monument("456 Monument St", "Liberty Bell", "1753", "Bronze", 4);
    EXPECT_EQ(m->getCondition(), 4);
    delete m;
}

TEST(LandmarkTest, CenterCreation) {
    LandMarkFactory landmarkFactory;
    Center* c = new Center("789 Center Rd", "Community Center", "2000", 3);
    EXPECT_EQ(c->getCondition(), 3);
    delete c;
}

// Test suite for Residential Buildings
TEST(ResidentialBuildingTest, HouseCreation) {
    ResidentialBuildingFactory residentialFactory;
    House* newHouse = new House("somewhere", 18);
    EXPECT_EQ(newHouse->getAddress(), "somewhere");
    delete newHouse;
}

TEST(ResidentialBuildingTest, FlatCreation) {
    ResidentialBuildingFactory residentialFactory;
    Flat* newFlat = new Flat("nowhere", 100);
    EXPECT_EQ(newFlat->getAddress(), "nowhere");
    delete newFlat;
}

TEST(ResidentialBuildingTest, TownHouseCreation) {
    ResidentialBuildingFactory residentialFactory;
    TownHouse* newTH = new TownHouse("up", 4);
    EXPECT_EQ(newTH->getAddress(), "up");
    delete newTH;
}

TEST(ResidentialBuildingTest, EstateCreation) {
    ResidentialBuildingFactory residentialFactory;
    Estate* newEstate = new Estate("down", 10, 25);
    EXPECT_EQ(newEstate->getAddress(), "down");
    delete newEstate;
}

// Test suite for Commercial Buildings
TEST(CommercialBuildingTest, ShopCreation) {
    CommericalBuildingFactory cF;
    Shop* newShop = new Shop("bikini-bottom", "KrabbyPatty", "Restaurant", 1);
    EXPECT_EQ(newShop->getAddress(), "bikini-bottom");
    delete newShop;
}

TEST(CommercialBuildingTest, OfficeCreation) {
    CommericalBuildingFactory cF;
    Office* newOffice = new Office("184 drive", "EASPORTS", "GAMING", 1);
    EXPECT_EQ(newOffice->getAddress(), "184 drive");
    delete newOffice;
}

TEST(CommercialBuildingTest, MallCreation) {
    CommericalBuildingFactory cF;
    Mall* newMall = new Mall("Midrand", "Mall of Africa", 2000);
    EXPECT_EQ(newMall->getAddress(), "Midrand");
    delete newMall;
}

// Test suite for Industrial Buildings
TEST(IndustrialBuildingTest, FactoryCreation) {
    IndustrialFactory industrialFactory;
    IndustrialBuilding* steelFactory = industrialFactory.createFactory();
    EXPECT_NE(steelFactory, nullptr);
    delete steelFactory;
}

TEST(IndustrialBuildingTest, WarehouseCreation) {
    IndustrialFactory industrialFactory;
    IndustrialBuilding* warehouse = industrialFactory.createWarehouse();
    EXPECT_NE(warehouse, nullptr);
    delete warehouse;
}

// Test suite for City Management
TEST(CityManagementTest, NotifyCitizens) {
    CityManager cityManager;
    EXPECT_NO_THROW(cityManager.notifyCitizens("Welcome to our city!"));
}

TEST(CityManagementTest, AllocateBudget) {
    CityManager cityManager;
    EXPECT_NO_THROW(cityManager.allocateBudget("Health", 50000.0));
}

TEST(CityManagementTest, RequestService) {
    CityManager cityManager;
    EXPECT_NO_THROW(cityManager.requestService("Health"));
}

// Test suite for Services
TEST(ServiceTest, HealthServices) {
    CityManager cityManager;
    HealthServices* healthServices = dynamic_cast<HealthServices*>(cityManager.getService("Health"));
    EXPECT_NE(healthServices, nullptr);
    if (healthServices) {
        EXPECT_NO_THROW(healthServices->admitPatient("John Doe"));
    }
}

TEST(ServiceTest, EducationServices) {
    CityManager cityManager;
    EducationServices* educationServices = dynamic_cast<EducationServices*>(cityManager.getService("Education"));
    EXPECT_NE(educationServices, nullptr);
    if (educationServices) {
        EXPECT_NO_THROW(educationServices->scheduleClass("Math 101"));
    }
}

TEST(ServiceTest, EntertainmentServices) {
    CityManager cityManager;
    EntertainmentServices* entertainmentServices = dynamic_cast<EntertainmentServices*>(cityManager.getService("Entertainment"));
    EXPECT_NE(entertainmentServices, nullptr);
    if (entertainmentServices) {
        EXPECT_NO_THROW(entertainmentServices->organizeEvent("Music Festival"));
    }
}

TEST(ServiceTest, SecurityServices) {
    CityManager cityManager;
    SecurityServices* securityServices = dynamic_cast<SecurityServices*>(cityManager.getService("Security"));
    EXPECT_NE(securityServices, nullptr);
    if (securityServices) {
        EXPECT_NO_THROW(securityServices->respondToEmergency("City Park"));
    }
}

TEST(ServiceTest, TransportationServices) {
    CityManager cityManager;
    TransportationServices* transportationServices = dynamic_cast<TransportationServices*>(cityManager.getService("Transportation"));
    EXPECT_NE(transportationServices, nullptr);
    if (transportationServices) {
        EXPECT_NO_THROW(transportationServices->manageSubsystems());
    }
}

// Test suite for PublicTransit
TEST(PublicTransitTest, AddVehicle) {
    CityManager cityManager;
    PublicTransit* publicTransit = dynamic_cast<PublicTransit*>(cityManager.getService("PublicTransit"));
    EXPECT_NE(publicTransit, nullptr);
    if (publicTransit) {
        EXPECT_NO_THROW(publicTransit->addVehicle("InterCity"));
    }
}

// Test suite for Trains
TEST(TrainsTest, AddTrain) {
    CityManager cityManager;
    Trains* trains = dynamic_cast<Trains*>(cityManager.getService("Trains"));
    EXPECT_NE(trains, nullptr);
    if (trains) {
        EXPECT_NO_THROW(trains->addTrain("Express Train"));
    }
}

// Test suite for Airports
TEST(AirportsTest, AddFlight) {
    CityManager cityManager;
    Airports* airports = dynamic_cast<Airports*>(cityManager.getService("Airports"));
    EXPECT_NE(airports, nullptr);
    if (airports) {
        EXPECT_NO_THROW(airports->addFlight("Flight 101"));
    }
}

// Test suite for Roads
TEST(RoadsTest, RepairRoad) {
    CityManager cityManager;
    Roads* roads = dynamic_cast<Roads*>(cityManager.getService("Roads"));
    EXPECT_NE(roads, nullptr);
    if (roads) {
        EXPECT_NO_THROW(roads->repairRoad());
    }
}

// Test suite for WastePlant
TEST(WastePlantTest, PerformMaintenance) {
    WastePlant wastePlant("WastePlant1", "Downtown", 1000);
    WastePlantObserver wasteManager("WasteManager1");
    wasteManager.attach(&wastePlant);
    EXPECT_NO_THROW(wastePlant.performMaintenance());
}

// Test suite for SewagePlant
TEST(SewagePlantTest, PerformMaintenance) {
    SewagePlant sewagePlant("SewagePlant1", "Midtown", 800);
    SewagePlantObserver sewageManager("SewageManager1");
    sewageManager.attach(&sewagePlant);
    EXPECT_NO_THROW(sewagePlant.performMaintenance());
}

// Test suite for WaterPlant
TEST(WaterPlantTest, PerformMaintenance) {
    WaterPlant waterPlant("WaterPlant1", "Riverside", 1200);
    WaterPlantObserver waterManager("WaterManager1");
    waterManager.attach(&waterPlant);
    EXPECT_NO_THROW(waterPlant.performMaintenance());
}

// Test suite for PowerPlant
TEST(PowerPlantTest, StartPlant) {
    PowerPlant powerPlant("PowerPlant1", "Uptown", 500.0);
    PowerPlantObserver powerManager("PowerManager1");
    powerManager.attach(&powerPlant);
    EXPECT_NO_THROW(powerPlant.startPlant());
}

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
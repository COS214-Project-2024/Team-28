#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>
#include "httplib.h"
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
#include "SewagePlantObserver.h"
#include "WaterPlantObserver.h"
#include "WaterPlant.h"

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
    httplib::Server server;
    CityManager cityManager;
    Government government;
    PayTaxes payTaxes(&cityManager);
    PayLevies payLevies(&cityManager);
    EconomicGrowthStrategy economicGrowthStrategy;
    SocialWelfareStrategy socialWelfareStrategy;
    HighPopulationStrategy highPopulationStrategy;
    std::vector<Citizen> citizens;

    server.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream file("index.html");
        if (file) {
            std::stringstream buffer;
            buffer << file.rdbuf();
            res.set_content(buffer.str(), "text/html");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/html");
        }
        res.set_header("Access-Control-Allow-Origin", "*");
    });

    server.Get("/buildings", [](const httplib::Request& req, httplib::Response& res) {
        std::string response = "Building Types:\n";
        response += "1. Residential\n";
        response += "2. Commercial\n";
        response += "3. Industrial\n";
        response += "4. Landmarks\n";
        res.set_content(response, "text/plain");
        res.set_header("Access-Control-Allow-Origin", "*");
    });

    server.Post("/buildings/residential/create",[] (const httplib::Request& req, httplib::Response& res) {
        std::string response = "Creating Building...\n";
        
        std::string type = req.get_param_value("type");
        if(type=="House"){
            std::string builingAddress = req.get_param_value("address");
            int numberOfResidents = std::stoi(req.get_param_value("residents"));
            House *house = new House(builingAddress, numberOfResidents);
        }
        else if(type=="Town House"){
            std::string builingAddress = req.get_param_value("address");
            int numberOfResidents = std::stoi(req.get_param_value("residents"));
            TownHouse *townHouse = new TownHouse(builingAddress, numberOfResidents);
        }
        else if(type=="Flat"){

        }
        else if(type=="Estate"){
            std::string builingAddress = req.get_param_value("address");
            int numberOfResidents = std::stoi(req.get_param_value("residents"));
            int numberOfUnits = std::stoi(req.get_param_value("units"));
            Estate *estate = new Estate(builingAddress, numberOfUnits, numberOfResidents);
        }
        res.set_header("Access-Control-Allow-Origin", "*");

    });

    server.Post("/citizens/create", [&government, &citizens](const httplib::Request& req, httplib::Response& res) {
        std::string response = "Creating Citizen...\n";
        std::string type = req.get_param_value("worker");

        bool hasHouse = req.get_param_value("hasHouse") == "true";
        if(type == "Worker"){
            double income = std::stod(req.get_param_value("income"));
            Worker worker(&government, hasHouse, income);
            citizens.push_back(worker);
            response += "Worker created: \n";
        } else if(type == "Dependent"){ 
            Dependent dependent(&government, std::stod(req.get_param_value("income")));
            citizens.push_back(dependent);
            response += "Dependent created: \n";
        }        
        response += "Citizen created \n";
        res.set_content(response, "text/html");
        res.set_header("Access-Control-Allow-Origin", "*");
    });

    server.set_mount_point("/images", "./images");

    std::cout << "City Sim Server is running at http://localhost:8080" << std::endl;
    server.listen("localhost", 8080);

    return 0;
}
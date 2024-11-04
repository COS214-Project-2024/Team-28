#include <iostream>
#include <vector>
#include <string>
#include "httplib.h"
#include "CityManager.h"
#include "Government.h"
#include "Citizen.h"
#include "Worker.h"
#include "Dependent.h"
#include "EconomicGrowthStrategy.h"
#include "SocialWelfareStrategy.h"
#include "HighPopulationStrategy.h"
#include "PayTaxes.h"
#include "PayLevies.h"
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
#include "SewagePlant.h"
#include "WaterPlantObserver.h"
#include "WaterPlant.h"

int main() {
    // Initialize CityManager and Government
    CityManager cityManager;
    Government government;
    PayTaxes payTaxes(&cityManager);
    PayLevies payLevies(&cityManager);
    EconomicGrowthStrategy economicGrowthStrategy;
    SocialWelfareStrategy socialWelfareStrategy;
    HighPopulationStrategy highPopulationStrategy;

    // Create and configure the HTTP server using httplib
    httplib::Server server;

    // Home page with navigation to all functionalities
    server.Get("/", [](const httplib::Request&, httplib::Response& res) {
        std::string html = R"(
        <html>
        <head><title>City Simulation</title></head>
        <body>
            <h1>City Simulation</h1>
            <ul>
                <li><a href="/citizens">View Citizens</a></li>
                <li><a href="/citizens/add">Add Citizen</a></li>
                <li><a href="/simulation/start">Start Simulation</a></li>
                <li><a href="/simulation/stop">Stop Simulation</a></li>
                <li><a href="/taxes/collect">Collect Taxes</a></li>
                <li><a href="/levies/collect">Collect Levies</a></li>
                <li><a href="/strategy/economic-growth">Apply Economic Growth Strategy</a></li>
                <li><a href="/strategy/social-welfare">Apply Social Welfare Strategy</a></li>
                <li><a href="/strategy/high-population">Apply High Population Strategy</a></li>
            </ul>
        </body>
        </html>
        )";
        res.set_content(html, "text/html");
    });

    // Endpoint to get all citizens
    server.Get("/citizens", [&cityManager](const httplib::Request&, httplib::Response& res) {
        std::vector<Citizen> citizens = cityManager.getCitizens();
        std::string response = "Citizens:\n";
        for (const auto& citizen : citizens) {
            response += "Name: " + citizen.getName() + ", Salary: " + std::to_string(citizen.getSalary()) + "\n";
        }
        res.set_content(response, "text/plain");
    });

    // Endpoint to add a new citizen
    server.Post("/citizens/add", [&cityManager](const httplib::Request& req, httplib::Response& res) {
        auto params = req.params;
        std::string name = params.get("name");
        double salary = std::stod(params.get("salary"));
        bool isHouseOwner = params.get("isHouseOwner") == "true";

        Citizen newCitizen(name, salary, isHouseOwner);
        cityManager.addCitizen(newCitizen);

        res.set_content("Citizen added successfully", "text/plain");
    });

    // Endpoint to start the simulation
    server.Get("/simulation/start", [&cityManager](const httplib::Request&, httplib::Response& res) {
        cityManager.startSimulation();
        res.set_content("Simulation started", "text/plain");
    });

    // Endpoint to stop the simulation
    server.Get("/simulation/stop", [&cityManager](const httplib::Request&, httplib::Response& res) {
        cityManager.stopSimulation();
        res.set_content("Simulation stopped", "text/plain");
    });

    // Endpoint to collect taxes
    server.Get("/taxes/collect", [&government](const httplib::Request&, httplib::Response& res) {
        government.payTaxes();
        res.set_content("Taxes collected", "text/plain");
    });

    // Endpoint to collect levies
    server.Get("/levies/collect", [&cityManager](const httplib::Request&, httplib::Response& res) {
        cityManager.payLevies();
        res.set_content("Levies collected", "text/plain");
    });

    // Endpoint to apply economic growth strategy
    server.Get("/strategy/economic-growth", [&government, &economicGrowthStrategy](const httplib::Request&, httplib::Response& res) {
        government.setStrategy(&economicGrowthStrategy);
        government.executeStrategy();
        res.set_content("Economic Growth Strategy applied", "text/plain");
    });

    // Endpoint to apply social welfare strategy
    server.Get("/strategy/social-welfare", [&government, &socialWelfareStrategy](const httplib::Request&, httplib::Response& res) {
        government.setStrategy(&socialWelfareStrategy);
        government.executeStrategy();
        res.set_content("Social Welfare Strategy applied", "text/plain");
    });

    // Endpoint to apply high population strategy
    server.Get("/strategy/high-population", [&government, &highPopulationStrategy](const httplib::Request&, httplib::Response& res) {
        government.setStrategy(&highPopulationStrategy);
        government.executeStrategy();
        res.set_content("High Population Strategy applied", "text/plain");
    });

    // Start the server and listen on localhost at port 8080
    std::cout << "City Simulation Server is running at http://localhost:8080" << std::endl;
    server.listen("localhost", 8080);

    return 0;
}
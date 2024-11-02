#include <iostream>
#include <vector>
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

void printCitizenSatisfaction(const std::vector<Citizen>& citizens) {
    for (const auto& citizen : citizens) {
        std::cout << "Citizen satisfaction: " << citizen.getSatisfaction() << std::endl;
    }
}

int main() {
    CityManager cityManager;
    Government government;
    PayTaxes payTaxes(&cityManager);
    PayLevies payLevies(&cityManager);
    EconomicGrowthStrategy economicGrowthStrategy;
    SocialWelfareStrategy socialWelfareStrategy;
    HighPopulationStrategy highPopulationStrategy;

    // Notify citizens
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;
    cityManager.notifyCitizens("Welcome to our city!");
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;

    // Manage services
    cityManager.manageServices();

    // Allocate budgets
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;
    cityManager.allocateBudget("Health", 50000.0);
    cityManager.allocateBudget("Education", 30000.0);
    cityManager.allocateBudget("Entertainment", 20000.0);
    cityManager.allocateBudget("Security", 40000.0);
    cityManager.allocateBudget("Transportation", 60000.0);
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;
    // Request services
    cityManager.requestService("Health");
    cityManager.requestService("Education");
    cityManager.requestService("Entertainment");
    cityManager.requestService("Security");
    cityManager.requestService("Transportation");
    std::cout << std::endl;

    // Test HealthServices
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;    
    std::cout << "Testing HealthServices..." << std::endl;
    HealthServices* healthServices = dynamic_cast<HealthServices*>(cityManager.getService("Health"));
    if (healthServices) {
        healthServices->admitPatient("John Doe");
        healthServices->admitPatient("Jane Doe");
        healthServices->admitPatient("Alice Smith");
        healthServices->admitPatient("Bob Johnson");
        healthServices->admitPatient("Charlie Brown");
        std::cout << std::endl;
        std::cout << "##########################################################################################################################" << std::endl;
        std::cout << std::endl;
        healthServices->provideTreatment("John Doe");
        healthServices->provideTreatment("Jane Doe");
        healthServices->provideTreatment("Alice Smith");
        healthServices->provideTreatment("Bob Johnson");
        healthServices->provideTreatment("Charlie Brown");
    }

    // Test EducationServices
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;    
    std::cout << "Testing EducationServices..." << std::endl;
    EducationServices* educationServices = dynamic_cast<EducationServices*>(cityManager.getService("Education"));
    if (educationServices) {
        educationServices->scheduleClass("Math 101");
        educationServices->scheduleClass("Science 101");
        educationServices->scheduleClass("History 101");
        educationServices->scheduleClass("English 101");
        educationServices->scheduleClass("Art 101");
        educationServices->recruitTeacher("Jane Smith");
        educationServices->recruitTeacher("John Smith");
        educationServices->recruitTeacher("Alice Johnson");
        educationServices->recruitTeacher("Bob Brown");
        educationServices->recruitTeacher("Charlie Davis");
    }

    // Test EntertainmentServices
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;
    std::cout << "Testing EntertainmentServices..." << std::endl;
    EntertainmentServices* entertainmentServices = dynamic_cast<EntertainmentServices*>(cityManager.getService("Entertainment"));
    if (entertainmentServices) {
        entertainmentServices->organizeEvent("Music Festival");
        entertainmentServices->organizeEvent("Movie Night");
        entertainmentServices->organizeEvent("Art Exhibition");
        entertainmentServices->cancelEvent("Music Festival");
        entertainmentServices->cancelEvent("Movie Night");
        entertainmentServices->cancelEvent("Art Exhibition");
    }

    // Test SecurityServices
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;    
    std::cout << "Testing SecurityServices..." << std::endl;
    SecurityServices* securityServices = dynamic_cast<SecurityServices*>(cityManager.getService("Security"));
    if (securityServices) {
        securityServices->respondToEmergency("City Park");
        securityServices->respondToEmergency("Main Street");
        securityServices->respondToEmergency("Central Square");
        securityServices->conductPatrol();
    }

    // Test TransportationServices and its subsystems
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;       
    std::cout << "Testing TransportationServices and its subsystems..." << std::endl;
    TransportationServices* transportationServices = dynamic_cast<TransportationServices*>(cityManager.getService("Transportation"));
    if (transportationServices) {
        transportationServices->manageSubsystems();
    }

    // Test PublicTransit
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;      
    std::cout << "Testing PublicTransit..." << std::endl;
    PublicTransit* publicTransit = dynamic_cast<PublicTransit*>(cityManager.getService("PublicTransit"));
    if (publicTransit) {
        publicTransit->addVehicle("InterCity");
        publicTransit->addVehicle("Eagleliner");
        publicTransit->addVehicle("Greyhound");
        publicTransit->removeVehicle("InterCity");
        publicTransit->removeVehicle("Eagleliner");
        publicTransit->removeVehicle("Greyhound");
        publicTransit->announceDelay(10);
    }

    // Test Trains
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;      
    std::cout << "Testing Trains..." << std::endl;
    Trains* trains = dynamic_cast<Trains*>(cityManager.getService("Trains"));
    if (trains) {
        trains->addTrain("Express Train");
        trains->addTrain("Local Train");
        trains->addTrain("High-Speed Train");
        trains->removeTrain("Express Train");
        trains->removeTrain("Local Train");
        trains->removeTrain("High-Speed Train");
        trains->scheduleTrain("City Route");
        trains->scheduleTrain("Suburban Route");
        trains->scheduleTrain("Intercity Route");
        trains->announceDelay(5);
    }

    // Test Airports
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;      
    std::cout << "Testing Airports..." << std::endl;
    Airports* airports = dynamic_cast<Airports*>(cityManager.getService("Airports"));
    if (airports) {
        airports->addFlight("Flight 101");
        airports->addFlight("Flight 102");
        airports->addFlight("Flight 103");
        airports->removeFlight("Flight 101");
        airports->removeFlight("Flight 102");
        airports->removeFlight("Flight 103");
        airports->scheduleFlightMaintenance();
    }

    // Test Roads
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;      
    std::cout << "Testing Roads..." << std::endl;
    Roads* roads = dynamic_cast<Roads*>(cityManager.getService("Roads"));
    if (roads) {
        roads->repairRoad();
        roads->expandLanes(2);
        roads->regulateTraffic();
    }

    // Create some citizens
    std::vector<Citizen> citizens;
    citizens.push_back(Worker(&government, true, 50000.0)); // Worker with house
    citizens.push_back(Worker(&government, false, 60000.0)); // Worker without house
    citizens.push_back(Dependent(&government, true)); // Dependent with house
    citizens.push_back(Dependent(&government, false)); // Dependent without house
    citizens.push_back(Worker(&government, true, 70000.0)); // Worker with house

    // Set citizens in the government
    government.setCitizens(citizens);

    // Apply Economic Growth Strategy
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;      
    std::cout << "Applying Economic Growth Strategy..." << std::endl;
    government.setStrategy(&economicGrowthStrategy);
    government.executeStrategy();
    printCitizenSatisfaction(citizens);

    // Apply Social Welfare Strategy
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;      
    std::cout << "Applying Social Welfare Strategy..." << std::endl;
    government.setStrategy(&socialWelfareStrategy);
    government.executeStrategy();
    printCitizenSatisfaction(citizens);

    // Citizens acknowledge receiving grants
    std::cout << "Citizens acknowledge receiving grants:" << std::endl;
    for (auto& citizen : citizens) {
        citizen.acknowledgeGrant();
    }

    // Apply High Population Strategy
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;      
    std::cout << "Applying High Population Strategy..." << std::endl;
    government.setStrategy(&highPopulationStrategy);
    government.executeStrategy();
    printCitizenSatisfaction(citizens);

    // Collect taxes
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;      
    std::cout << "Collecting taxes..." << std::endl;
    government.payTaxes();
    printCitizenSatisfaction(citizens);

    // Collect levies
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;      
    std::cout << "Collecting levies..." << std::endl;
    cityManager.payLevies(citizens);
    printCitizenSatisfaction(citizens);

    // Execute commands
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;      
    std::cout << "Executing commands..." << std::endl;
    government.setCommand(&payTaxes);
    government.executeCommand();
    printCitizenSatisfaction(citizens);

    government.setCommand(&payLevies);
    government.executeCommand();
    printCitizenSatisfaction(citizens);

    // Increase taxes and levies
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;      
    std::cout << "Increasing taxes and levies..." << std::endl;
    for (int i = 0; i < 5; ++i) {
        government.increaseTaxesAndLevies();
        for (auto& citizen : citizens) {
            citizen.updateSatisfaction();
        }
        printCitizenSatisfaction(citizens);
    }

    // Continuously lower taxes and levies
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;      
    std::cout << "Continuously lowering taxes and levies..." << std::endl;
    for (int i = 0; i < 3; ++i) {
        government.reduceLevies();
        government.setTaxRate(government.getTaxRate() * 0.9);
        for (auto& citizen : citizens) {
            citizen.updateSatisfaction();
        }
        printCitizenSatisfaction(citizens);
    }

    // Apply Economic Growth Strategy to stabilize levies and taxes
    std::cout << std::endl;
    std::cout << "##########################################################################################################################" << std::endl;
    std::cout << std::endl;      
    std::cout << "Applying Economic Growth Strategy to stabilize levies and taxes..." << std::endl;
    government.setStrategy(&economicGrowthStrategy);
    government.executeStrategy();
    printCitizenSatisfaction(citizens);

    return 0;
}
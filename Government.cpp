#include "Government.h"
#include <iostream>

Government::Government() : budget(0.0), taxRate(0.0), economicSituation(50), levyRate(10) {}

void Government::setTaxRate(double rate) {
    taxRate = rate;
}

double Government::getTaxRate() const {
    return taxRate;
}

void Government::collectTaxes(const std::vector<Citizen>& citizens) {
    double totalTaxes = 0.0;
    for (const auto& citizen : citizens) {
        totalTaxes += citizen.payTaxes();
    }
    budget += totalTaxes;
}

void Government::allocateBudget(const std::string& department, double amount) {
    // Implement budget allocation logic here
    budget += amount;
}

void Government::createPolicy(const std::string& policyName) {
    cityPolicies.push_back(policyName);
}

void Government::evaluateCitizenNeeds(const std::vector<Citizen>& citizens) {
    // Implement citizen needs evaluation logic here
}

void Government::setCommand(Command* command) {
    this->command = command;
}

void Government::executeCommand() {
    if (command) {
        command->execute();
    }
}

void Government::setStrategy(Strategy* strategy) {
    this->strategy = strategy;
}

void Government::executeStrategy() {
    if (strategy) {
        strategy->executeStrategy(this);
    }
}

void Government::reduceLevies() {
    levyRate -= 5; // Example reduction
    updateEconomicSituation(0, 0, 5); // Positive effect on economic situation
}

void Government::increaseTaxesAndLevies() {
    taxRate += 0.05; // Example increase
    levyRate += 5; // Example increase
    updateEconomicSituation(0, -5, -5); // Negative effect on economic situation
}

std::vector<Citizen> Government::getCitizens() const {
    return citizens;
}

void Government::setCitizens(const std::vector<Citizen>& citizens) {
    this->citizens = citizens;
}

void Government::updateEconomicSituation(int policyEffect, int taxEffect, int economicEffect) {
    economicSituation += policyEffect + taxEffect + economicEffect;
    economicSituation = std::max(0, std::min(100, economicSituation)); // Clamp economic situation between 0 and 100
}

int Government::getEconomicSituation() const {
    return economicSituation;
}

void Government::payTaxes() {
    for (auto& citizen : citizens) {
        if (dynamic_cast<Worker*>(&citizen)) {
            std::cout << "Worker: Noted, paying taxes." << std::endl;
            budget += citizen.payTaxes();
        }
    }
}

void Government::manageResidentialBuildings(const std::vector<ResidentialBuilding*>& buildings, BuildingFactory* factory, int expectedNumber) {
    int numberOfBuildings = buildings.size();
    std::cout << "Number of residential buildings: " << numberOfBuildings << std::endl;

    if (numberOfBuildings > expectedNumber) {
        std::cout << "Number of buildings exceeds the expected number. Creating a new building..." << std::endl;
        ResidentialBuilding* newBuilding = factory->createHouse(); // Example: creating a new house
        if (newBuilding) {
            std::cout << "New building created." << std::endl;
        } else {
            std::cout << "Failed to create a new building." << std::endl;
        }
    }
}

void Government::checkEstateResidentsAndTriggerStrategy(Estate* estate, int expectedResidents) {
    int numberOfResidents = estate->getNumberOfResidents();
    std::cout << "Number of residents in the estate: " << numberOfResidents << std::endl;

    if (numberOfResidents > expectedResidents) {
        std::cout << "Number of residents exceeds the expected number. Triggering High Population Strategy..." << std::endl;
        HighPopulationStrategy highPopulationStrategy;
        setStrategy(&highPopulationStrategy);
        executeStrategy();
    }
}
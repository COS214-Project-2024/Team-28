#include "Government.h"

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
        totalTaxes += citizen.payTaxes(taxRate);
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
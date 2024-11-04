#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <vector>
#include <string>
#include "Command.h"
#include "Strategy.h"
#include "Citizen.h"
#include "Worker.h"
#include "ResidentialBuildings.h"
#include "BuildingFactory.h"
#include "HighPopulationStrategy.h"

class Government {
public:
    Government();
    void setTaxRate(double rate);
    double getTaxRate() const;
    void collectTaxes(const std::vector<Citizen>& citizens);
    void allocateBudget(const std::string& department, double amount);
    void createPolicy(const std::string& policyName);
    void evaluateCitizenNeeds(const std::vector<Citizen>& citizens);
    void setCommand(Command* command);
    void executeCommand();
    void setStrategy(Strategy* strategy);
    void executeStrategy();
    void reduceLevies();
    void increaseTaxesAndLevies();
    std::vector<Citizen> getCitizens() const;
    void setCitizens(const std::vector<Citizen>& citizens);
    void updateEconomicSituation(int policyEffect, int taxEffect, int economicEffect);
    int getEconomicSituation() const;
    void payTaxes();
    void manageResidentialBuildings(const std::vector<ResidentialBuilding*>& buildings, BuildingFactory* factory, int expectedNumber);
    void checkEstateResidentsAndTriggerStrategy(Estate* estate, int expectedResidents);

private:
    double budget;
    double taxRate;
    std::vector<std::string> cityPolicies;
    std::vector<std::string> publicServices;
    Command* command;
    Strategy* strategy;
    std::vector<Citizen> citizens;
    int economicSituation;
    int levyRate;
};

#endif // GOVERNMENT_H
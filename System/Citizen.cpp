#include "Citizen.h"
#include "Government.h"
#include <iostream>

Citizen::Citizen(Government* government, bool isHouseOwner) : satisfaction(50), government(government), striking(false), houseOwner(isHouseOwner) {}

double Citizen::payTaxes() const {
    return 0.0; // Default implementation for non-workers
}

void Citizen::receiveFoodHamper() {
    std::cout << "Citizen received a food hamper." << std::endl;
    satisfaction += 6; // Increase satisfaction by 6 for receiving a food hamper
    satisfaction = std::max(0, std::min(100, satisfaction)); // Clamp satisfaction between 0 and 100
}

void Citizen::receiveMoney(double amount) {
    std::cout << "Citizen received R" << amount << " money." << std::endl;
    satisfaction += 20; // Increase satisfaction by 20 for receiving money
    satisfaction = std::max(0, std::min(100, satisfaction)); // Clamp satisfaction between 0 and 100
}

void Citizen::acknowledgeGrant() {
    std::cout << "Citizen: Thank you for the grant! I appreciate it." << std::endl;
}

void Citizen::updateSatisfaction() {
    int economicSituation = government->getEconomicSituation();
    satisfaction = 50 + (economicSituation - 50) / 2; // Satisfaction is influenced by economic situation
    satisfaction = std::max(0, std::min(100, satisfaction)); // Clamp satisfaction between 0 and 100

    if (satisfaction < 30 && !striking) {
        strike();
    } else if (satisfaction >= 30 && striking) {
        stopStriking();
    }
}

int Citizen::getSatisfaction() const {
    return satisfaction;
}

void Citizen::strike() {
    striking = true;
    std::cout << "Citizen: We are striking due to low satisfaction!" << std::endl;
}

void Citizen::stopStriking() {
    striking = false;
    std::cout << "Citizen: We are no longer striking." << std::endl;
}

bool Citizen::isStriking() const {
    return striking;
}

void Citizen::setSatisfaction(int satisfaction) {
    this->satisfaction = satisfaction;
}

bool Citizen::isHouseOwner() const {
    return houseOwner;
}
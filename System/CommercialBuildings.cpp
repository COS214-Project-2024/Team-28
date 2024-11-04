#include "CommercialBuildings.h"

// MallShop implementation
MallShop::MallShop(std::string name, std::string type, double size, double rent)
    : name(name), type(type), size(size), rent(rent), revenue(0), operatingCosts(0), isOccupied(false) {
}

double MallShop::calculateMonthlyRevenue() const {
    return revenue - operatingCosts - rent;
}

void MallShop::setRevenue(double rev) {
    revenue = rev;
}

void MallShop::setOperatingCosts(double costs) {
    operatingCosts = costs;
}

bool MallShop::isVacant() const {
    return !isOccupied;
}

void MallShop::print() const {
    std::cout << "Shop Name: " << name << ", Type: " << type 
              << ", Area: " << type << ", Rent: " << rent 
              << ", Revenue: " << revenue << ", Operating Costs: " << operatingCosts << std::endl;
}

// EmergencySystem implementation
void EmergencySystem::triggerEvacuation() {
    std::cout << "Emergency evacuation triggered - all visitors evacuated" << std::endl;
}

void EmergencySystem::update(float deltaTime) {
    // Update emergency system state
}

// Mall implementation
Mall::Mall()
    : address(""), mallName(""), buildingCost(500), maxCapacity(0), currentVisitors(0), maxShops(2) {
    taxRates["municipal"] = 0.02;
    taxRates["property"] = 0.015;
    taxRates["income"] = 0.03;
}

Mall::Mall(std::string address, std::string mallName, int maxCapacity)
    : address(address), mallName(mallName), buildingCost(500), maxCapacity(maxCapacity), currentVisitors(0), maxShops(2) {
    taxRates["municipal"] = 0.02;
    taxRates["property"] = 0.015;
    taxRates["income"] = 0.03;
}

void Mall::addShop(const MallShop& shop) {
    if (shops.size() >= static_cast<size_t>(maxShops)) {
        throw std::runtime_error("Mall has reached maximum shop capacity");
    }
    shops.push_back(shop);
}

void Mall::printShops() const {
    for (const auto& shop : shops) {
        shop.print();
    }
}

bool Mall::admitVisitors(int count) {
    if (currentVisitors + count > maxCapacity) {
        return false;
    }
    currentVisitors += count;
    return true;
}

void Mall::exitVisitors(int count) {
    currentVisitors = std::max(0, currentVisitors - count);
}

double Mall::calculateMonthlyTaxes() const {
    double totalRevenue = 0;
    for (const auto& shop : shops) {
        totalRevenue += shop.calculateMonthlyRevenue();
    }

    double totalTax = 0;
    for (const auto& [type, rate] : taxRates) {
        totalTax += totalRevenue * rate;
    }
    return totalTax;
}

void Mall::triggerEmergencyEvacuation() {
    emergencySystem.triggerEvacuation();
}

void Mall::scheduleRoutineMaintenance(const std::string& area, const std::time_t& date) {
    maintenanceSchedule[date] = area;
}

float Mall::getBuildCost() const {
    return buildingCost;
}

std::string Mall::getAddress() const {
    return address;
}

void Mall::print() const {
    std::cout << "----------" << std::endl;
    std::cout << "Mall Details: " << std::endl;
    std::cout << "Mall Name: " << mallName << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Current Visitors: " << currentVisitors << "/" << maxCapacity << std::endl;
    std::cout << "Number of Shops: " << shops.size() << "/" << maxShops << std::endl;
    std::cout << "Monthly Tax Due: $" << calculateMonthlyTaxes() << std::endl;
    std::cout << "----------" << std::endl;
}

// Shop implementation
Shop::Shop() : CommercialBuilding(), address(""), shopName(""), typeOfShop(""), shopSize(0), buildingCost(50) {
}

Shop::Shop(std::string address, std::string shopName, std::string typeOfShop, int shopSize)
    : address(address), shopName(shopName), typeOfShop(typeOfShop), shopSize(shopSize), buildingCost(50) {
}

float Shop::getBuildCost() const {
    return buildingCost;
}

std::string Shop::getAddress() const {
    return address;
}

void Shop::print() const {
    std::cout << "----------" << std::endl;
    std::cout << "Shop Details: " << std::endl;
    std::cout << "Name: " << shopName << std::endl;
    std::cout << "Type: " << typeOfShop << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Shop Size Category: " << shopSize << std::endl;
    std::cout << "----------" << std::endl;
}

// Office implementation
Office::Office() : CommercialBuilding(), address(""), companyName(""), typeOfCompany(""), officeSize(0), buildingCost(70) {
}

Office::Office(std::string address, std::string companyName, std::string typeOfCompany, int officeSize)
    : address(address), companyName(companyName), typeOfCompany(typeOfCompany), officeSize(officeSize), buildingCost(70) {
}

float Office::getBuildCost() const {
    return buildingCost;
}

std::string Office::getAddress() const {
    return address;
}

void Office::print() const {
    std::cout << "----------" << std::endl;
    std::cout << "Office Details: " << std::endl;
    std::cout << "Name: " << companyName << std::endl;
    std::cout << "Type: " << typeOfCompany << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Office Size Category: " << officeSize << std::endl;
    std::cout << "----------" << std::endl;
}
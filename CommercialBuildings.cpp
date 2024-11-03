#include "CommercialBuildings.h"

// MallShop implementation
MallShop::MallShop(std::string name, std::string type, double size, double rent)
    : name(name), type(type), size(size), rent(rent), revenue(0), operatingCosts(0), isOccupied(false) {}

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
    isEvacuationActive = true;
    currentEvacuationTime = 0;
}

void EmergencySystem::update(float deltaTime) {
    if (isEvacuationActive) {
        currentEvacuationTime += deltaTime;
        if (currentEvacuationTime >= 900.0f) {
            isEvacuationActive = false;
        }
    }
}

// Mall implementation
Mall::Mall() : CommercialBuilding(), address(""), mallName(""),  buildingCost(500), maxCapacity(0), currentVisitors(0), maxShops(2) {}

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
    for (const auto& taxRate : taxRates) {
        totalTax += totalRevenue * taxRate.second;
    }
    return totalTax;
}

void Mall::triggerEmergencyEvacuation() {
    emergencySystem.triggerEvacuation();
    currentVisitors = 0;
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
ShopUnit::ShopUnit(std::string name, std::string department, double size, double rent)
    : name(name), department(department), size(size), rent(rent), revenue(0), operatingCosts(0), isOccupied(false) {
}

double ShopUnit::calculateMonthlyRevenue() const {
    return revenue - operatingCosts - rent;
}

void ShopUnit::setRevenue(double rev) {
    revenue = rev;
}

void ShopUnit::setOperatingCosts(double costs) {
    operatingCosts = costs;
}

bool ShopUnit::isVacant() const {
    return !isOccupied;
}

void ShopUnit::print() const {
    std::cout << "Unit Name: " << name << ", Department: " << department 
              << ", Size: " << size << ", Rent: " << rent 
              << ", Revenue: " << revenue << ", Operating Costs: " << operatingCosts << std::endl;
}

// Shop implementation
Shop::Shop()
    : address(""), shopName(""), buildingCost(50), maxCapacity(0), currentCustomers(0), maxUnits(5) {
    taxRates["sales"] = 0.08;     // Different tax structure for retail
    taxRates["property"] = 0.015;
    taxRates["income"] = 0.025;
}

Shop::Shop(std::string address, std::string shopName, int maxCapacity)
    : address(address), shopName(shopName), buildingCost(50), maxCapacity(maxCapacity), 
      currentCustomers(0), maxUnits(5) {
    taxRates["sales"] = 0.08;
    taxRates["property"] = 0.015;
    taxRates["income"] = 0.025;
}

void Shop::addUnit(const ShopUnit& unit) {
    if (units.size() >= static_cast<size_t>(maxUnits)) {
        throw std::runtime_error("Shop has reached maximum unit capacity");
    }
    units.push_back(unit);
}

void Shop::printUnits() const {
    for (const auto& unit : units) {
        unit.print();
    }
}

bool Shop::admitCustomers(int count) {
    if (currentCustomers + count > maxCapacity) {
        return false;
    }
    currentCustomers += count;
    return true;
}

void Shop::exitCustomers(int count) {
    currentCustomers = std::max(0, currentCustomers - count);
}

double Shop::calculateMonthlyTaxes() const {
    double totalRevenue = 0;
    for (const auto& unit : units) {
        totalRevenue += unit.calculateMonthlyRevenue();
    }

    double totalTax = 0;
    for (const auto& taxRate : taxRates) {
        totalTax += totalRevenue * taxRate.second;
    }
    return totalTax;
}

void Shop::triggerEmergencyEvacuation() {
    emergencySystem.triggerEvacuation();
}

void Shop::scheduleRoutineMaintenance(const std::string& area, const std::time_t& date) {
    maintenanceSchedule[date] = area;
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
    std::cout << "Shop Name: " << shopName << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Current Customers: " << currentCustomers << "/" << maxCapacity << std::endl;
    std::cout << "Number of Units: " << units.size() << "/" << maxUnits << std::endl;
    std::cout << "Monthly Tax Due: $" << calculateMonthlyTaxes() << std::endl;
    std::cout << "----------" << std::endl;
}

// Office implementation
OfficeUnit::OfficeUnit(std::string name, std::string department, double size, double rent)
    : name(name), department(department), size(size), rent(rent), revenue(0), operatingCosts(0), isOccupied(false) {
}

double OfficeUnit::calculateMonthlyRevenue() const {
    return revenue - operatingCosts - rent;
}

void OfficeUnit::setRevenue(double rev) {
    revenue = rev;
}

void OfficeUnit::setOperatingCosts(double costs) {
    operatingCosts = costs;
}

bool OfficeUnit::isVacant() const {
    return !isOccupied;
}

void OfficeUnit::print() const {
    std::cout << "Unit Name: " << name << ", Department: " << department 
              << ", Size: " << size << ", Rent: " << rent 
              << ", Revenue: " << revenue << ", Operating Costs: " << operatingCosts << std::endl;
}

// Office implementation
Office::Office()
    : address(""), companyName(""), buildingCost(400), maxCapacity(0), currentEmployees(0), maxUnits(10) {
    taxRates["municipal"] = 0.02;
    taxRates["property"] = 0.015;
    taxRates["income"] = 0.03;
}

Office::Office(std::string address, std::string companyName, int maxCapacity)
    : address(address), companyName(companyName), buildingCost(400), maxCapacity(maxCapacity), 
      currentEmployees(0), maxUnits(10) {
    taxRates["municipal"] = 0.02;
    taxRates["property"] = 0.015;
    taxRates["income"] = 0.03;
}

void Office::addUnit(const OfficeUnit& unit) {
    if (units.size() >= static_cast<size_t>(maxUnits)) {
        throw std::runtime_error("Office has reached maximum unit capacity");
    }
    units.push_back(unit);
}

void Office::printUnits() const {
    for (const auto& unit : units) {
        unit.print();
    }
}

bool Office::admitEmployees(int count) {
    if (currentEmployees + count > maxCapacity) {
        return false;
    }
    currentEmployees += count;
    return true;
}

void Office::exitEmployees(int count) {
    currentEmployees = std::max(0, currentEmployees - count);
}

double Office::calculateMonthlyTaxes() const {
    double totalRevenue = 0;
    for (const auto& unit : units) {
        totalRevenue += unit.calculateMonthlyRevenue();
    }

    double totalTax = 0;
    for (const auto& taxRate : taxRates) {
        totalTax += totalRevenue * taxRate.second;
    }
    return totalTax;
}

void Office::triggerEmergencyEvacuation() {
    emergencySystem.triggerEvacuation();
}

void Office::scheduleRoutineMaintenance(const std::string& area, const std::time_t& date) {
    maintenanceSchedule[date] = area;
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
    std::cout << "Company Name: " << companyName << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Current Employees: " << currentEmployees << "/" << maxCapacity << std::endl;
    std::cout << "Number of Units: " << units.size() << "/" << maxUnits << std::endl;
    std::cout << "Monthly Tax Due: $" << calculateMonthlyTaxes() << std::endl;
    std::cout << "----------" << std::endl;
}
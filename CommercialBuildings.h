#ifndef COMMERCIALBUILDINGS_H
#define COMMERCIALBUILDINGS_H


//Concrete Products of the Commerical Building Abstract Product 
//Shops, offices, malls.


#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>
#include <ctime>

#include "Building.h"

// class Shop;
// class Office;

//-------------------------------------------------------------------------------------
class MallShop {
public:
    MallShop(std::string name, std::string type, double size, double rent) 
        : name(name), type(type), size(size), rent(rent), isOccupied(false) {}

    double calculateMonthlyRevenue() const {
        return revenue - operatingCosts - rent;
    }

    void setRevenue(double rev) { revenue = rev; }
    void setOperatingCosts(double costs) { operatingCosts = costs; }
    bool isVacant() const { return !isOccupied; }

    void print() const {
        std::cout << "Shop Name: " << name << ", Type: " << type 
                  << ", Area: " << type << ", Rent: " << rent 
                  << ", Revenue: " << revenue << ", Operating Costs: " << operatingCosts << std::endl;
    }

private:
    std::string name;
    std::string type;
    double size;        // in square meters
    double rent;
    double revenue = 0;
    double operatingCosts = 0;
    bool isOccupied;
};

class EmergencySystem {
public:
    void triggerEvacuation() {
        isEvacuationActive = true;
        currentEvacuationTime = 0;
    }

    void update(float deltaTime) {
        if (isEvacuationActive) {
            currentEvacuationTime += deltaTime;
            // Typically takes 15 minutes to evacuate
            if (currentEvacuationTime >= 900.0f) {
                isEvacuationActive = false;
            }
        }
    }

private:
    bool isEvacuationActive = false;
    float currentEvacuationTime = 0;
};

class Mall : public CommercialBuilding {
public:
    Mall() : CommercialBuilding() {
        this->address = "";
        this->mallName = "";
        this->maxCapacity = 0;
        this->buildingCost = 500;
        this->currentVisitors = 0;
    }

    Mall(std::string address, std::string mallName, int maxCapacity) 
        : address(address), mallName(mallName), maxCapacity(maxCapacity) {
        taxRates["municipal"] = 0.02;  // 2% municipal tax
        taxRates["property"] = 0.015;  // 1.5% property tax
        taxRates["income"] = 0.03;     // 3% income tax
    }

    // Shop management
    void addShop(const MallShop& shop) {
        if (shops.size() >= maxShops) {
            throw std::runtime_error("Mall has reached maximum shop capacity");
        }
        shops.push_back(shop);
    }

    void printShops() const {
        for (const auto& shop : shops) {
            shop.print();
        }
    }

    // Visitor management
    bool admitVisitors(int count) {
        if (currentVisitors + count > maxCapacity) {
            return false;
        }
        currentVisitors += count;
        return true;
    }

    void exitVisitors(int count) {
        currentVisitors = std::max(0, currentVisitors - count);
    }

    double calculateMonthlyTaxes() const {
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

    void triggerEmergencyEvacuation() {
        emergencySystem.triggerEvacuation();
        currentVisitors = 0;  // Everyone evacuates
    }

    void scheduleRoutineMaintenance(const std::string& area, const std::time_t& date) {
        maintenanceSchedule[date] = area;
    }

    // Required override methods
    float getBuildCost() const override {
        return buildingCost;
    }

    std::string getAddress() const override {
        return address;
    }

    void print() const override {
        std::cout << "----------" << std::endl;
        std::cout << "Mall Details: " << std::endl;
        std::cout << "Mall Name: " << mallName << std::endl;
        std::cout << "Address: " << address << std::endl;
        std::cout << "Current Visitors: " << currentVisitors << "/" << maxCapacity << std::endl;
        std::cout << "Number of Shops: " << shops.size() << "/" << maxShops << std::endl;
        std::cout << "Monthly Tax Due: $" << calculateMonthlyTaxes() << std::endl;
        std::cout << "----------" << std::endl;
    }

private:
    std::string address;
    std::string mallName;
    float buildingCost;
    
    // Capacity management
    int maxCapacity;        // Maximum number of visitors
    int currentVisitors;
    const int maxShops = 2;  // Maximum number of shop units
    
    // Components
    std::vector<MallShop> shops;
    EmergencySystem emergencySystem;
    std::map<std::string, double> taxRates;
    std::map<std::time_t, std::string> maintenanceSchedule;
};
//-------------------------------------------------------------------------------------

class Shop : public CommercialBuilding {
public:
    Shop() : CommercialBuilding() {
        this->address = "";
        this->shopName = "";
        this->typeOfShop = "";
        this->shopSize = 0;
        this->buildingCost = 50;
    }
    Shop(std::string address, std::string shopName, std::string typeOfShop, int shopSize) {
        this->address = address;
        this->shopName = shopName;
        this->typeOfShop = typeOfShop;
        this->shopSize = shopSize;
        this->buildingCost = 50;  // Default cost, if it's constant
    }

    float getBuildCost() const override {  // Marked as const
        return this->buildingCost;  // Return building cost for comparisons
    }

    std::string getAddress() const override {  // Marked as const
        return this->address;
    }

    void print() const override {
        std::cout << "----------" << std::endl;
        std::cout << "Shop Details: " << std::endl;
        std::cout << "Name: " << shopName << std::endl;
        std::cout << "Type: " << typeOfShop << std::endl;
        std::cout << "Address: " << address << std::endl;
        std::cout << "Shop Size Category: " << shopSize << std::endl;
        std::cout << "----------" << std::endl;
    }

private:
    std::string address;
    std::string shopName;
    std::string typeOfShop;
    int shopSize;
    float buildingCost;
};

class Office : public CommercialBuilding {
public:
    Office() : CommercialBuilding() {
        this->address = "";
        this->companyName = "";
        this->typeOfCompany = "";
        this->officeSize = 0;
        this->buildingCost = 70;
    }
    Office(std::string address, std::string companyName, std::string typeOfCompany, int officeSize) {
        this->address = address;
        this->companyName = companyName;
        this->typeOfCompany = typeOfCompany;
        this->officeSize = officeSize;
        this->buildingCost = 70;  // Default cost, if it's constant
    }

    float getBuildCost() const override {  // Marked as const
        return this->buildingCost;  // Return building cost for comparisons
    }

    std::string getAddress() const override {  // Marked as const
        return this->address;
    }

    void print() const override {
        std::cout << "----------" << std::endl;
        std::cout << "Office Details: " << std::endl;
        std::cout << "Name: " << companyName << std::endl;
        std::cout << "Type: " << typeOfCompany << std::endl;
        std::cout << "Address: " << address << std::endl;
        std::cout << "Office Size Category: " << officeSize << std::endl;
        std::cout << "----------" << std::endl;
    }

private:
    std::string address;
    std::string companyName;
    std::string typeOfCompany;
    int officeSize;
    float buildingCost;
};


// class Mall: public CommercialBuilding{
//     public:
//      Mall():CommercialBuilding(){
//             this->address = "";
//             this->mallName = "";
//             this->numberOfStores = 0;
//             this->buildingCost = 500;

//         }
//         Mall(std::string address, std::string mallName,int numberOfStores ){
//             this->address = address;
//             this->mallName = mallName;
//             this->numberOfStores= numberOfStores;

//         }
//         float getBuildCost(){
//             return this->buildingCost;          // return building cost for comparisons 
//         }
//         ~Mall() = default;
//         int getSize(){
//             return this->numberOfStores;
//         }
//         std::string getAddress(){   //We dont want same adresses 
//             return this->address;
//         }

//         void print() const override{
//             std::cout<<"----------"<<std::endl;
//             std::cout<<"Mall Details: "<<std::endl;
//             std::cout<<"Mall Name: "<<mallName<<std::endl;
//             std::cout<<"Number of Stores: "<<numberOfStores<<std::endl;
//             std::cout<<"Address: "<<address<<std::endl;
//             std::cout<<"----------"<<std::endl;
//         }
//     /*
//         if we want mall to be made up of shops and offices
//          //getNumberOfUnits and buildCost will change 
//     */


//     private:
//         std::string address;
//         std::string mallName;
//         int numberOfStores;           // we will take taxes depoending on howw big the sie is, example shopSize 1 shops will pay 10, shopSize 2 will pay 20 etc
//         float buildingCost;
       
//         //If we want a mall to be made up of diiferent shops and offices intead of stores
//         /*
//             Shop*  shops;
//             Office* offices;
//             */
// };
#endif
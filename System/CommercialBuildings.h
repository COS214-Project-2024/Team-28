#ifndef COMMERCIALBUILDINGS_H
#define COMMERCIALBUILDINGS_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>
#include <ctime>

#include "Building.h"
#include "IndustrialBuilding.h"

class MallShop {
public:
    MallShop(std::string name, std::string type, double size, double rent);

    double calculateMonthlyRevenue() const;
    void setRevenue(double rev);
    void setOperatingCosts(double costs);
    bool isVacant() const;
    void print() const;

private:
    std::string name;
    std::string type;
    double size;
    double rent;
    double revenue;
    double operatingCosts;
    bool isOccupied;
};

class EmergencySystem {
public:
    void triggerEvacuation();
    void update(float deltaTime);

private:
    bool isEvacuationActive;
    float currentEvacuationTime;
};

class Mall : public CommercialBuilding {
public:
    Mall();
    Mall(std::string address, std::string mallName, int maxCapacity);

    void addShop(const MallShop& shop);
    void printShops() const;
    bool admitVisitors(int count);
    void exitVisitors(int count);
    double calculateMonthlyTaxes() const;
    void triggerEmergencyEvacuation();
    void scheduleRoutineMaintenance(const std::string& area, const std::time_t& date);

    float getBuildCost() const override;
    std::string getAddress() const override;
    void print() const override;

private:
    std::string address;
    std::string mallName;
    float buildingCost;
    int maxCapacity;
    int currentVisitors;
    const int maxShops;
    std::vector<MallShop> shops;
    EmergencySystem emergencySystem;
    std::map<std::string, double> taxRates;
    std::map<std::time_t, std::string> maintenanceSchedule;
};

class Shop : public CommercialBuilding {
public:
    Shop();
    Shop(std::string address, std::string shopName, std::string typeOfShop, int shopSize);

    float getBuildCost() const override;
    std::string getAddress() const override;
    void print() const override;

private:
    std::string address;
    std::string shopName;
    std::string typeOfShop;
    int shopSize;
    float buildingCost;
};

class Office : public CommercialBuilding {
public:
    Office();
    Office(std::string address, std::string companyName, std::string typeOfCompany, int officeSize);

    float getBuildCost() const override;
    std::string getAddress() const override;
    void print() const override;

private:
    std::string address;
    std::string companyName;
    std::string typeOfCompany;
    int officeSize;
    float buildingCost;
};

#endif // COMMERCIALBUILDINGS_H
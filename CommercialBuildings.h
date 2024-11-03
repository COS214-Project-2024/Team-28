// CommercialBuildings.h
#ifndef COMMERCIALBUILDINGS_H
#define COMMERCIALBUILDINGS_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>
#include <ctime>
#include "Building.h"

/**
 * @class MallShop
 * @brief Represents a shop within a mall.
 *
 * The MallShop class provides information about a shop's name,
 * type, size, rent, revenue, and operating costs. It also includes
 * methods to calculate revenue and determine occupancy status.
 */
class MallShop {
public:
    /**
     * @brief Constructs a MallShop object.
     * @param name Name of the shop.
     * @param type Type of the shop.
     * @param size Size of the shop in square meters.
     * @param rent Monthly rent of the shop.
     */
    MallShop(std::string name, std::string type, double size, double rent);

    /**
     * @brief Calculates the monthly revenue of the shop.
     * @return Monthly revenue.
     */
    double calculateMonthlyRevenue() const;

    /**
     * @brief Sets the revenue of the shop.
     * @param rev New revenue amount.
     */
    void setRevenue(double rev);

    /**
     * @brief Sets the operating costs of the shop.
     * @param costs New operating costs.
     */
    void setOperatingCosts(double costs);

    /**
     * @brief Checks if the shop is vacant.
     * @return True if the shop is vacant, false otherwise.
     */
    bool isVacant() const;

    /**
     * @brief Prints the details of the shop.
     */
    void print() const;

private:
    std::string name;         ///< Name of the shop
    std::string type;         ///< Type of the shop
    double size;              ///< Size of the shop
    double rent;              ///< Rent of the shop
    double revenue;           ///< Revenue of the shop
    double operatingCosts;    ///< Operating costs of the shop
    bool isOccupied;          ///< Occupancy status of the shop
};

/**
 * @class EmergencySystem
 * @brief Manages emergency procedures for a mall.
 *
 * The EmergencySystem class is responsible for triggering
 * evacuations and updating the status of the evacuation process.
 */
class EmergencySystem {
public:
    /**
     * @brief Triggers the emergency evacuation procedure.
     */
    void triggerEvacuation();

    /**
     * @brief Updates the evacuation status based on the time delta.
     * @param deltaTime Time since the last update.
     */
    void update(float deltaTime);

private:
    bool isEvacuationActive;   ///< Status of the evacuation
    float currentEvacuationTime; ///< Current evacuation time
};

/**
 * @class Mall
 * @brief Represents a shopping mall.
 *
 * The Mall class contains information about the mall's address,
 * name, maximum capacity, and current visitors. It allows adding
 * shops, admitting and exiting visitors, calculating taxes, and
 * handling emergencies.
 */
class Mall : public CommercialBuilding {
public:
    /**
     * @brief Default constructor for Mall.
     */
    Mall();

    /**
     * @brief Constructs a Mall object.
     * @param address Address of the mall.
     * @param mallName Name of the mall.
     * @param maxCapacity Maximum capacity of visitors in the mall.
     */
    Mall(std::string address, std::string mallName, int maxCapacity);

    /**
     * @brief Adds a shop to the mall.
     * @param shop The shop to be added.
     */
    void addShop(const MallShop& shop);

    /**
     * @brief Prints the list of shops in the mall.
     */
    void printShops() const;

    /**
     * @brief Admits visitors to the mall.
     * @param count Number of visitors to admit.
     * @return True if admission is successful, false otherwise.
     */
    bool admitVisitors(int count);

    /**
     * @brief Exits visitors from the mall.
     * @param count Number of visitors to exit.
     */
    void exitVisitors(int count);

    /**
     * @brief Calculates the monthly taxes for the mall.
     * @return Total monthly taxes.
     */
    double calculateMonthlyTaxes() const;

    /**
     * @brief Triggers an emergency evacuation in the mall.
     */
    void triggerEmergencyEvacuation();

    /**
     * @brief Schedules routine maintenance for a specific area.
     * @param area Area that needs maintenance.
     * @param date Scheduled date for maintenance.
     */
    void scheduleRoutineMaintenance(const std::string& area, const std::time_t& date);

    /**
     * @brief Gets the construction cost of the mall.
     * @return Building cost.
     */
    float getBuildCost() const override;

    /**
     * @brief Gets the address of the mall.
     * @return Address of the mall.
     */
    std::string getAddress() const override;

    /**
     * @brief Prints the details of the mall.
     */
    void print() const override;

private:
    std::string address;       ///< Address of the mall
    std::string mallName;      ///< Name of the mall
    float buildingCost;        ///< Construction cost of the mall
    int maxCapacity;           ///< Maximum capacity of visitors
    int currentVisitors;       ///< Current number of visitors
    const int maxShops;       ///< Maximum number of shops
    std::vector<MallShop> shops; ///< List of shops in the mall
    EmergencySystem emergencySystem; ///< Emergency system of the mall
    std::map<std::string, double> taxRates; ///< Tax rates for different services
    std::map<std::time_t, std::string> maintenanceSchedule; ///< Maintenance schedule
};

/**
 * @class Shop
 * @brief Represents a shop in a commercial area.
 *
 * The Shop class contains information about the shop's address,
 * name, type, size, and construction cost.
 */
class Shop : public CommercialBuilding {
public:
    /**
     * @brief Default constructor for Shop.
     */
    Shop();

    /**
     * @brief Constructs a Shop object.
     * @param address Address of the shop.
     * @param shopName Name of the shop.
     * @param typeOfShop Type of the shop.
     * @param shopSize Size of the shop.
     */
    Shop(std::string address, std::string shopName, std::string typeOfShop, int shopSize);

    /**
     * @brief Gets the construction cost of the shop.
     * @return Building cost.
     */
    float getBuildCost() const override;

    /**
     * @brief Gets the address of the shop.
     * @return Address of the shop.
     */
    std::string getAddress() const override;

    /**
     * @brief Prints the details of the shop.
     */
    void print() const override;

private:
    std::string address;       ///< Address of the shop
    std::string shopName;      ///< Name of the shop
    std::string typeOfShop;    ///< Type of the shop
    int shopSize;              ///< Size of the shop
    float buildingCost;        ///< Construction cost of the shop
};

/**
 * @class Office
 * @brief Represents an office in a commercial area.
 *
 * The Office class contains information about the office's address,
 * company name, type of company, size, and construction cost.
 */
class Office : public CommercialBuilding {
public:
    /**
     * @brief Default constructor for Office.
     */
    Office();

    /**
     * @brief Constructs an Office object.
     * @param address Address of the office.
     * @param companyName Name of the company.
     * @param typeOfCompany Type of the company.
     * @param officeSize Size of the office.
     */
    Office(std::string address, std::string companyName, std::string typeOfCompany, int officeSize);

    /**
     * @brief Gets the construction cost of the office.
     * @return Building cost.
     */
    float getBuildCost() const override;

    /**
     * @brief Gets the address of the office.
     * @return Address of the office.
     */
    std::string getAddress() const override;

    /**
     * @brief Prints the details of the office.
     */
    void print() const override;

private:
    std::string address;       ///< Address of the office
    std::string companyName;   ///< Name of the company
    std::string typeOfCompany; ///< Type of the company
    int officeSize;            ///< Size of the office
    float buildingCost;        ///< Construction cost of the office
};

#endif // COMMERCIALBUILDINGS_H

// CommercialTests.h
#pragma once
#include <cassert>
#include <iostream>
#include <sstream>
#include "CommercialBuildings.h"

class CommercialTests {
private:
    static void printTestResult(const std::string& testName, bool passed) {
        std::cout << (passed ? "[PASS] " : "[FAIL] ") << testName << std::endl;
    }

    // Mall Tests
    static void testMallShopCreation() {
        MallShop shop("Test Shop", "Retail", 100.0, 1000.0);
        bool passed = shop.isVacant() && 
                     shop.calculateMonthlyRevenue() == -1000.0;
        printTestResult("Mall Shop Creation", passed);
    }

    static void testMallShopFinancials() {
        MallShop shop("Test Shop", "Retail", 100.0, 1000.0);
        shop.setRevenue(5000.0);
        shop.setOperatingCosts(2000.0);
        bool passed = shop.calculateMonthlyRevenue() == 2000.0;
        printTestResult("Mall Shop Financials", passed);
    }

    static void testMallVisitorCapacity() {
        Mall mall("Test Address", "Test Mall", 1000);
        bool passed = mall.admitVisitors(500) &&
                     mall.admitVisitors(600) == false;
        printTestResult("Mall Visitor Capacity", passed);
    }

    static void testMallTaxCalculation() {
        Mall mall("Test Address", "Test Mall", 1000);
        MallShop shop("Test Shop", "Retail", 100.0, 1000.0);
        shop.setRevenue(10000.0);
        shop.setOperatingCosts(5000.0);
        mall.addShop(shop);
        
        double expectedTax = 4000.0 * (0.02 + 0.015 + 0.03);
        double actualTax = mall.calculateMonthlyTaxes();
        bool passed = std::abs(expectedTax - actualTax) < 0.01;
        printTestResult("Mall Tax Calculation", passed);
    }

    // Office Tests
    static void testOfficeUnitCreation() {
        OfficeUnit unit("HR", "Administration", 150.0, 2000.0);
        bool passed = unit.isVacant() && 
                     unit.calculateMonthlyRevenue() == -2000.0;
        printTestResult("Office Unit Creation", passed);
    }

    static void testOfficeEmployeeCapacity() {
        Office office("Test Address", "Test Company", 200);
        bool passed = office.admitEmployees(100) &&
                     office.admitEmployees(150) == false;
        printTestResult("Office Employee Capacity", passed);
    }

    static void testOfficeTaxCalculation() {
        Office office("Test Address", "Test Company", 200);
        OfficeUnit unit("HR", "Administration", 150.0, 2000.0);
        unit.setRevenue(8000.0);
        unit.setOperatingCosts(3000.0);
        office.addUnit(unit);
        
        double expectedTax = 3000.0 * (0.02 + 0.015 + 0.03);
        double actualTax = office.calculateMonthlyTaxes();
        bool passed = std::abs(expectedTax - actualTax) < 0.01;
        printTestResult("Office Tax Calculation", passed);
    }

    // Shop Tests
    static void testShopUnitCreation() {
        ShopUnit unit("Groceries", "Food", 200.0, 1500.0);
        bool passed = unit.isVacant() && 
                     unit.calculateMonthlyRevenue() == -1500.0;
        printTestResult("Shop Unit Creation", passed);
    }

    static void testShopCustomerCapacity() {
        Shop shop("Test Address", "Test Shop", 150);
        bool passed = shop.admitCustomers(75) &&
                     shop.admitCustomers(100) == false; 
        printTestResult("Shop Customer Capacity", passed);
    }

    static void testShopTaxCalculation() {
        Shop shop("Test Address", "Test Shop", 150);
        ShopUnit unit("Groceries", "Food", 200.0, 1500.0);
        unit.setRevenue(6000.0);
        unit.setOperatingCosts(2500.0);
        shop.addUnit(unit);
        
        double expectedTax = 2000.0 * (0.08 + 0.015 + 0.025);
        double actualTax = shop.calculateMonthlyTaxes();
        bool passed = std::abs(expectedTax - actualTax) < 0.01;
        printTestResult("Shop Tax Calculation", passed);
    }

    // Emergency System Tests
    static void testEmergencySystem() {
        EmergencySystem system;
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
        
        system.triggerEvacuation();
        std::cout.rdbuf(oldCout);
        
        bool passed = buffer.str().find("Emergency evacuation triggered") != std::string::npos;
        printTestResult("Emergency System", passed);
    }

public:
    static void runAllTests() {
        std::cout << "\n=== Running Mall Tests ===\n";
        testMallShopCreation();
        testMallShopFinancials();
        testMallVisitorCapacity();
        testMallTaxCalculation();

        std::cout << "\n=== Running Office Tests ===\n";
        testOfficeUnitCreation();
        testOfficeEmployeeCapacity();
        testOfficeTaxCalculation();

        std::cout << "\n=== Running Shop Tests ===\n";
        testShopUnitCreation();
        testShopCustomerCapacity();
        testShopTaxCalculation();

        std::cout << "\n=== Running Emergency System Tests ===\n";
        testEmergencySystem();
    }
};
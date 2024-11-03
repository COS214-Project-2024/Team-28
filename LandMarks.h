#ifndef LANDMARKS_H
#define LANDMARKS_H

#include <iostream>
#include "Building.h"

class Park : public Landmark {
public:
    Park();
    Park(std::string address, std::string nameOfPark, std::string date, int condition);
    float getBuildCost();
    int getCondition();
    std::string getAddress();
    void print() const override;
    ~Park() = default;

private:
    std::string address;
    std::string nameOfPark;
    std::string dateEstablished;
    int condition;
    float buildingCost;
};

class Monument : public Landmark {
public:
    Monument();
    Monument(std::string location, std::string nameOfMonument, std::string date, std::string material, int condition);
    float getBuildCost();
    int getCondition();
    void print() const override;
    ~Monument() = default;

private:
    std::string location;
    std::string nameOfMonument;
    std::string materialUsed;
    std::string dateEstablished;
    int condition;
    float buildingCost;
};
class Center : public Landmark {
public:
    Center();
    Center(std::string address, std::string nameOfCenter, std::string date, int condition);
    float getBuildCost();
    int getCondition();
    void print() const override;
    ~Center() = default;

private:
    std::string address;
    std::string nameOfCenter;
    std::string description;
    std::string dateEstablished;
    int condition;
    float buildingCost;
};

#endif

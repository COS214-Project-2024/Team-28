#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
//ABSTRACT PRODUCTS

class Building{ //
    public:
        Building() = default;
        ~Building() = default;
        virtual void print() const = 0;

};

class ResidentialBuilding : public Building {
public:
    virtual ~ResidentialBuilding() = default;
};


class CommercialBuilding : public Building {
public:
    virtual ~CommercialBuilding() = default;
    virtual float getBuildCost() const = 0;
    virtual std::string getAddress() const = 0;
    virtual void print() const = 0;
};

class IndustrialBuilding : public Building {
public:
    virtual ~IndustrialBuilding() = default;
    virtual void construct() = 0;
    virtual void maintain() = 0;
    virtual void startProduction() = 0;
    virtual void stopProduction() = 0;
    virtual void hireWorker(const std::string& workerName) = 0;
    virtual void allocateJobs() = 0;
    virtual int getNumberOfWorkers() const = 0;
    virtual void print() const = 0;
};

class Landmark : public Building {
public:
    virtual ~Landmark() = default;
};

#endif

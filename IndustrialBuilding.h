// IndustrialBuilding.h
#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H
#include "Building.h"
#include <string>

class IndustrialBuilding : public Building {
public:
    IndustrialBuilding(const std::string& name, const std::string& location, int capacity)
        : name(name), location(location), capacity(capacity) {}

   // Pure virtual functions
    virtual void startOperation() = 0;
    virtual void stopOperation() = 0;
    virtual void performInspection() = 0;
    virtual std::string getBuildingDetails() const = 0;
    virtual ~IndustrialBuilding() = default;
    virtual void construct() = 0;
    virtual void maintain() = 0;
    virtual void startProduction() = 0;
    virtual void stopProduction() = 0;
    virtual void hireWorker(const std::string& workerName) = 0;
    virtual void allocateJobs() = 0;
    virtual int getNumberOfWorkers() const = 0;
    virtual void print() const = 0;
    // Getters
    std::string getName() const { return name; }
    std::string getLocation() const { return location; }
    int getCapacity() const { return capacity; }

protected:
    std::string name;
    std::string location;
    int capacity;
};

#endif // INDUSTRIALBUILDING_H

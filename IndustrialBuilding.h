// IndustrialBuilding.h
#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H

#include <string>

class IndustrialBuilding {
public:
    IndustrialBuilding(const std::string& name, const std::string& location, int capacity)
        : name(name), location(location), capacity(capacity) {}

    virtual ~IndustrialBuilding() = default;

    // Pure virtual functions
    virtual void startOperation() = 0;
    virtual void stopOperation() = 0;
    virtual void performInspection() = 0;
    virtual std::string getBuildingDetails() const = 0;

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

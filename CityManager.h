// CityManager.h
#ifndef CITYMANAGER_H
#define CITYMANAGER_H

#include <string>

class CityManager {
public:
    CityManager(const std::string& managerName)
        : name(managerName) {}

    virtual ~CityManager() = default;
    virtual void reportStatus() const = 0;
    std::string getName() const { return name; }
     
protected:
    std::string name;
    // double electricityUsage ;
    // double waterUsage;
    // double cityWaste;
    // double citySewage;
};

#endif =

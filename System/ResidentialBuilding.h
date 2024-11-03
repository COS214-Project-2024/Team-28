// ResidentialBuilding.h

#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include <string>
#include <vector>
#include "Citizen.h"

class ResidentialBuilding {
private:
    std::string address;
    double maintenanceCost;
    int capacity;
    std::vector<Citizen> residents;
    
public:
    ResidentialBuilding(std::string addr, double cost, int cap);
  
    void addResidents(const std::vector<Citizen>& newResidents);

    void removeResidents(const std::vector<Citizen>& leavingResidents);

    std::vector<Citizen>::iterator getResidents();

    int getOccupancy() const;

    static ResidentialBuilding* create();
};

#endif // RESIDENTIALBUILDING_H

#ifndef PlantsManager_h
#define PlantsManager_h

#include <string>    // Include the string header for std::string
#include "CityManager.h"

class Plants;
class PlantStateHandler;

class PlantsManager : public CityManager {
private:
    std::string state;
    int capacity;
    int operationHours;

public:
    // Plants* unnamed_Plants;
    // PlantStateHandler* unnamed_PlantStateHandler;

    void initiateFaultHandling(const std::string& faultType);
    void restorePlantOperations();
    void performRoutineMaintenance();
    void changeState(const std::string& newState);
    void fixPlant();
    void push();
};

#endif  // PlantsManager_h

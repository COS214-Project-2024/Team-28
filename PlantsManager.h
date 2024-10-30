#ifndef PlantsManager_h
#define PlantsManager_h

#include <string>    
#include "CityManager.h"

class Plants;
class PlantStateHandler;

enum class PlantState {
    Operational,
    FaultActive,
    UnderMaintenance,
    Fixed
};
class PlantsManager : public CityManager {

private:
    PlantState state;
      std::vector<Observer*> observers;
     bool faultActive;

public:
    void attach(Observer* observer);
    void detach(Observer* observer);

    void notify();
    
    void initiateFaultHandling(const std::string& faultType);
    void restorePlantOperations();
    void performRoutineMaintenance();
    void changeState(const std::string& newState);
    void fixPlant();
    
};

#endif  // PlantsManager_h

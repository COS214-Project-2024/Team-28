#ifndef PlantsManager_h
#define PlantsManager_h

#include <string>
#include "CityManager.h"
#include "Plant.h"

class Plants;
class PlantStateHandler;

class PlantsManager : public CityManager
{

private:
    PlantState* state;
    std::vector<Plant *> observers;
    bool faultActive;

public:
    void attach(Plant *observer);
    void detach(Plant *observer);

    void notify();

    void initiateFaultHandling(const std::string &faultType);
    void restorePlantOperations();
    void performRoutineMaintenance();
    void changeState(const std::string &newState);
    void fixPlant();
    virtual void update();
};

#endif // PlantsManager_h

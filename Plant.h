#ifndef PLANT_H
#define PLANT_H
#include <string>
#include "PlantState.h"
#include "PlantsManager.h"

class Plant
{
    private:
        std::string plantName;
        std::string location;
        int capacity;
        PlantState currentState;

    public:
        Plant();
        ~Plant();
        void startplant();
        void stopPlant();
        void performMaintenance();
        std::string getPlantDetails();
        void attachManager(PlantsManager* manager);
        void detachManager(PlantsManager* manager);
        void notifyManagers();
        // void changeState(const std::string& newState);
        // void fixPlant();
        // void push();
        // void initiateFaultHandling(const std::string& faultType);
        // void restorePlantOperations();

};
#endif
// PlantsManager.h
#ifndef PLANTSMANAGER_H
#define PLANTSMANAGER_H

#include <string>
#include <vector>

// Forward declaration of Plant and PlantState
class Plant;
class PlantState;

class PlantsManager {
public:
    PlantsManager(const std::string& name) : name(name) {}
    virtual ~PlantsManager() {}

    void attach(Plant* plant);
    void detach(Plant* plant);

    // Pure virtual functions to be implemented by derived classes
    virtual void update(Plant* plant, PlantState* state) = 0;
    virtual void initiateFaultHandling(const std::string& faultType) = 0;
    virtual void restorePlantOperations() = 0;
    virtual void performRoutineMaintenance(Plant* plant) = 0;
    virtual void changeState(Plant* plant, const std::string& newState) = 0;
    virtual void reportStatus() const = 0;
    virtual void allocateResources() = 0;

    // Public accessor for manager's name
    std::string getName() const { return name; }

protected:
    std::string name;
    std::vector<Plant*> plants;
};

#endif // PLANTSMANAGER_H

// PlantState.h
#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include <string>

// Forward declaration
class Plant;

class PlantState {
public:
    PlantState();
    virtual ~PlantState();
    virtual void handleState(Plant* plant) = 0;
    virtual std::string getStateName() = 0;
};

#endif // PLANTSTATE_H

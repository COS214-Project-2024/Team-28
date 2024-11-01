// PlantState.h
#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include <string>

// Forward declaration
class Plant;

class PlantState {
public:
    virtual ~PlantState() = default;
    virtual void handleState(Plant* plant) = 0;
    virtual std::string getStateName() const = 0;
};

#endif // PLANTSTATE_H

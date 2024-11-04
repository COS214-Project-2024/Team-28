// SewagePlantState.h
#ifndef SEWAGEPLANTSTATE_H
#define SEWAGEPLANTSTATE_H

#include "PlantState.h"
#include <string>

// Forward declaration to avoid circular dependencies
class SewagePlant;

class SewagePlantState : public PlantState {
public:
    // Default constructor
    SewagePlantState() : PlantState() {}
    
    // Virtual Destructor
    virtual ~SewagePlantState() {}
    
    // Pure virtual methods
    virtual void handleState(Plant* plant) override = 0;
    virtual std::string getStateName() override = 0;
};

#endif // SEWAGEPLANTSTATE_H

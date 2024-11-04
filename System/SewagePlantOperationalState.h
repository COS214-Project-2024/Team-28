// SewagePlantOperationalState.h
#ifndef SEWAGEPLANTOPERATIONALSTATE_H
#define SEWAGEPLANTOPERATIONALSTATE_H

#include "SewagePlantState.h"
#include <string>

class SewagePlantOperationalState : public SewagePlantState
{
public:
    // Constructors
    SewagePlantOperationalState() : SewagePlantState(), isOperational(true) {}
    
    // Destructor
    ~SewagePlantOperationalState() override {}
    
    // Override handleState method
    void handleState(Plant* plant) override;
    
    // Override getStateName method
    std::string getStateName() override;
    
private:
    bool isOperational;
};

#endif // SEWAGEPLANTOPERATIONALSTATE_H

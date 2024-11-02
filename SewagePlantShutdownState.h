// SewagePlantShutdownState.h
#ifndef SEWAGEPLANTSHUTDOWNSTATE_H
#define SEWAGEPLANTSHUTDOWNSTATE_H

#include "SewagePlantState.h"
#include <string>

class SewagePlantShutdownState : public SewagePlantState
{
public:
    // Constructors
    SewagePlantShutdownState() : SewagePlantState(), isFailed(false) {}
    SewagePlantShutdownState(bool isFailed) : SewagePlantState(), isFailed(isFailed) {}
    
    // Destructor
    ~SewagePlantShutdownState() override {}
    
    // Override handleState method
    void handleState(Plant* plant) override;
    
    // Override getStateName method
    std::string getStateName() override;
    
private:
    bool isFailed;
};

#endif // SEWAGEPLANTSHUTDOWNSTATE_H

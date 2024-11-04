// SewagePlantFailureState.h
#ifndef SEWAGEPLANTFAILURESTATE_H
#define SEWAGEPLANTFAILURESTATE_H

#include "SewagePlantState.h"
#include <string>

// Forward declaration if Plant is used as a pointer
class Plant;

class SewagePlantFailureState : public SewagePlantState
{
private:
    bool isFailed;

public:
    // Constructors
    SewagePlantFailureState(bool isFailed)
        : SewagePlantState(), isFailed(isFailed) {}

    SewagePlantFailureState()
        : SewagePlantState(), isFailed(false) {}
    
    // Destructor
    ~SewagePlantFailureState() override {}

    // Override handleState method
    void handleState(Plant* plant) override;

    // Override getStateName method
    std::string getStateName() override;
};

#endif // SEWAGEPLANTFAILURESTATE_H

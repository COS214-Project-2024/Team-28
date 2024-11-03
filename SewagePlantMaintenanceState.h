// SewagePlantMaintenanceState.h
#ifndef SEWAGEPLANTMAINTENANCESTATE_H
#define SEWAGEPLANTMAINTENANCESTATE_H

#include "SewagePlantState.h"
#include <string>

class SewagePlantMaintenanceState : public SewagePlantState
{
public:
    // Constructors
    SewagePlantMaintenanceState() : SewagePlantState() {}
    
    // Destructor
    ~SewagePlantMaintenanceState() override {}
    
    // Override handleState method
    void handleState(Plant* plant) override;
    
    // Override getStateName method
    std::string getStateName() override;
};

#endif // SEWAGEPLANTMAINTENANCESTATE_H

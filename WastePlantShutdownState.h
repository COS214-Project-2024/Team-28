#ifndef WASTEPLANTSHUTDOWNSTATE_H
#define WASTEPLANTSHUTDOWNSTATE_H
#include "WastePlantState.h"
#include "WastePlantOperationalState.h"
class WastePlantShutdownState : public WastePlantState
{
private:
    bool isOperational;

public:
    WastePlantShutdownState(){};
   ~WastePlantShutdownState();
    WastePlantShutdownState(WastePlantOperationalState *operationalState);
    virtual void handleState(Plant* plant) override;
    virtual std::string getStateName() const override;
   
};
#endif
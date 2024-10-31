#ifndef WASTEPLANTSHUTDOWNSTATE_H
#define WASTEPLANTSHUTDOWNSTATE_H
#include "WastePlantState.h"
#include "WastePlantOperationalState.h"
class WastePlantShutdownState : public WastePlantState
{
private:
    WastePlantOperationalState *operationalState;

public:
    WastePlantShutdownState(WastePlantOperationalState *operationalState);
    void handleWasteState() override;
    ~WastePlantShutdownState();
};
#endif
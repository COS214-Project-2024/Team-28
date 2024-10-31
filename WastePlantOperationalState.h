#ifndef WASTEPLANTOPERATIONALSTATE_H
#define WASTEPLANTOPERATIONALSTATE_H
#include "WastePlantState.h"

class WastePlantOperationalState : public WastePlantState
{
private:
    bool isOperational;
public:
    WastePlantOperationalState(/* args */);
    ~WastePlantOperationalState();
    void handleWasteState() override;
    void setOperational(bool operational);
};
#endif
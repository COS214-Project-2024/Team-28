// WastePlantState.h
#ifndef WASTEPLANTSTATE_H
#define WASTEPLANTSTATE_H
#include "PlantState.h"

#include "PlantState.h"

class WastePlantState : public PlantState {
public:
    WastePlantState(/* args */);
    ~WastePlantState();
    virtual void handleState(Plant*) = 0;
};

#endif // WASTEPLANTSTATE_H

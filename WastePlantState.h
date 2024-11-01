// WastePlantState.h
#ifndef WASTEPLANTSTATE_H
#define WASTEPLANTSTATE_H

#include "PlantState.h"

class WastePlantState : public PlantState {
public:
    virtual ~WastePlantState() = default;
    virtual void handleState(Plant* plant) override = 0;
};

#endif // WASTEPLANTSTATE_H

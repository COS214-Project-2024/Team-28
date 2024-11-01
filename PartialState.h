// PartialState.h
#ifndef PARTIALSTATE_H
#define PARTIALSTATE_H

#include "PlantState.h"
#include <iostream>

class PartialState : public PlantState {
public:
    void handleState(Plant* plant) override;
    std::string getStateName() const override { return "PartialState"; }
};

#endif // PARTIALSTATE_H

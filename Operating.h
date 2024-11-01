// Operating.h
#ifndef OPERATING_H
#define OPERATING_H
#include "PlantState.h"
#include <iostream>

class Operating : public PlantState {
public:
    virtual ~Operating() = default;
    virtual void handleState(Plant* plant) override;
    virtual std::string getStateName() const override;
};

#endif // OPERATING_H
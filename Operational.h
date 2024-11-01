// Operational.h
#ifndef OPERATIONAL_H
#define OPERATIONAL_H
#include "PlantState.h"
#include <iostream>

class Operational : public PlantState {
public:
    
    virtual ~Operational() = default;
    

    virtual void handleState(Plant* plant) override;
    virtual std::string getStateName() const override;
};

#endif // OPERATIONAL_H
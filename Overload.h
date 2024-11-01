#ifndef OVERLOAD_H
#define OVERLOAD_H

#include "PlantState.h"
#include <iostream>
// Forward declaration of the Plant class
//class Plant;

class Overload : public PlantState {
public:
void handleState(Plant* plant) override;
    std::string getStateName() const override { return "Overload"; }
};

#endif // OVERLOAD_H

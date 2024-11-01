// Shutdown.h
#ifndef SHUTDOWN_H
#define SHUTDOWN_H

#include "PlantState.h"
#include <iostream>

class Shutdown : public PlantState {
public:
    void handleState(Plant* plant) override;
    std::string getStateName() const override { return "Shutdown"; }
};

#endif // SHUTDOWN_H

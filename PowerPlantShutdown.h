#ifndef POWERPLANTSHUTDOWN_H
#define POWERPLANTSHUTDOWN_H

#include "PlantState.h"
#include <iostream>
//#include <string>
//class Plant;

class PowerPlantShutdown : public PlantState {
public:
  void handleState(Plant* plant) override;
    std::string getStateName() const override { return "Shutdown"; }
};

#endif // POWERPLANTSHUTDOWN_H

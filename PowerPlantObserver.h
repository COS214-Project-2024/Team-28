#ifndef POWERPLANTOBSERVER_H
#define POWERPLANTOBSERVER_H

#include <iostream>
#include "PlantsManager.h"

class PowerPlantObserver : public Observer {
public:
    void update() override;
};

#endif // POWERPLANTOBSERVER_H

// PayLevies.h
#ifndef PAYLEVIES_H
#define PAYLEVIES_H

#include "Command.h"
#include "CityManager.h"

class PayLevies : public Command {
public:
    PayLevies(CityManager* cityManager) : cityManager(cityManager) {}
    void execute() override;

private:
    CityManager* cityManager;
};

#endif // PAYLEVIES_H
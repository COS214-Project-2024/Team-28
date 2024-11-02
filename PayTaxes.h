#ifndef PAYTAXES_H
#define PAYTAXES_H

#include "Command.h"
#include "CityManager.h"

class PayTaxes : public Command {
public:
    PayTaxes(CityManager* cityManager) : cityManager(cityManager) {}
    void execute() override;

private:
    CityManager* cityManager;
};

#endif // PAYTAXES_H
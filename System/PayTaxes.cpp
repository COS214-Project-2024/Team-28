// PayTaxes.cpp
#include "PayTaxes.h"

void PayTaxes::execute() {
    cityManager->notifyCitizens("Taxes payment due.");
}
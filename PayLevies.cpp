// PayLevies.cpp
#include "PayLevies.h"

void PayLevies::execute() {
    cityManager->notifyCitizens("Levies payment due.");
}
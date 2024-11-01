#include "EconomicGrowthStrategy.h"
#include "Government.h"

void EconomicGrowthStrategy::executeStrategy(Government* government) {
    // Increase the government budget
    government->allocateBudget("General", 1000000.0); // Example budget allocation

    // Restore tax rate to normal
    government->setTaxRate(0.1); // Example normal tax rate

    // Restore levies to normal
    government->reduceLevies();

    // Restore economic situation to normal
    government->updateEconomicSituation(0, 0, 50 - government->getEconomicSituation());

    // Restore citizen satisfaction to 50
    std::vector<Citizen> citizens = government->getCitizens();
    for (auto& citizen : citizens) {
        citizen.setSatisfaction(50);
    }
}
#ifndef HIGHPOPULATIONSTRATEGY_H
#define HIGHPOPULATIONSTRATEGY_H

#include "Strategy.h"
#include "Government.h"
#include "ResidentialBuildingFactory.h"

class HighPopulationStrategy : public Strategy {
public:
    void executeStrategy(Government* government) override;
};

#endif // HIGHPOPULATIONSTRATEGY_H
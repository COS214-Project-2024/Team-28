#ifndef ECONOMICGROWTHSTRATEGY_H
#define ECONOMICGROWTHSTRATEGY_H

#include "Strategy.h"
#include "Government.h"

class EconomicGrowthStrategy : public Strategy {
public:
    void executeStrategy(Government* government) override;
};

#endif // ECONOMICGROWTHSTRATEGY_H
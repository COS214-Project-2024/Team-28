// EconomicGrowthStrategy.h
#ifndef ECONOMICGROWTHSTRATEGY_H
#define ECONOMICGROWTHSTRATEGY_H

#include "Strategy.h"
#include "Government.h"

/**
 * @class EconomicGrowthStrategy
 * @brief Strategy implementation for promoting economic growth.
 *
 * The EconomicGrowthStrategy class implements a strategy
 * that focuses on enhancing the economic performance of a
 * government through various initiatives and policies.
 */
class EconomicGrowthStrategy : public Strategy {
public:
    /**
     * @brief Executes the economic growth strategy.
     *
     * This method applies the economic growth strategies to
     * the given government, potentially modifying its policies
     * and actions to foster economic development.
     *
     * @param government A pointer to the Government instance
     *        to which the strategy will be applied.
     */
    void executeStrategy(Government* government) override;
};

#endif // ECONOMICGROWTHSTRATEGY_H

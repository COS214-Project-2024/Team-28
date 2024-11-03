// HighPopulationStrategy.h
#ifndef HIGHPOPULATIONSTRATEGY_H
#define HIGHPOPULATIONSTRATEGY_H

#include "Strategy.h"
#include "Government.h"

/**
 * @class HighPopulationStrategy
 * @brief Strategy for managing government actions in a high population scenario.
 *
 * The HighPopulationStrategy class implements the Strategy interface, 
 * providing specific actions and policies that the government should follow 
 * when dealing with a high population density.
 */
class HighPopulationStrategy : public Strategy {
public:
    /**
     * @brief Executes the strategy for the given government.
     *
     * This method contains the logic to adapt governmental policies and services 
     * to effectively manage resources and address the needs of a high population.
     *
     * @param government Pointer to the Government object to which the strategy is applied.
     */
    void executeStrategy(Government* government) override;
};

#endif // HIGHPOPULATIONSTRATEGY_H

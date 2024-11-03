#ifndef STRATEGY_H
#define STRATEGY_H

class Government;

/**
 * @class Strategy
 * @brief Abstract base class for strategy patterns.
 *
 * This class defines the interface for different strategy implementations
 * that can be applied within a Government context. Each concrete strategy
 * must provide an implementation for the executeStrategy method.
 */
class Strategy {
public:
    /**
     * @brief Executes the strategy for the specified government.
     * 
     * This method is intended to be overridden by derived classes
     * to implement specific strategies for government operations.
     * 
     * @param government A pointer to the Government object
     *                   that will utilize this strategy.
     */
    virtual void executeStrategy(Government* government) = 0;

    /// Default virtual destructor.
    virtual ~Strategy() = default;
};

#endif // STRATEGY_H

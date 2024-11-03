#ifndef SOCIALWELFARESTRATEGY_H
#define SOCIALWELFARESTRATEGY_H

#include "Strategy.h"
#include "Government.h"

/**
 * @class SocialWelfareStrategy
 * @brief A strategy class for implementing social welfare policies.
 *
 * This class implements the Strategy interface and provides
 * a concrete strategy for executing social welfare initiatives
 * within a government context.
 */
class SocialWelfareStrategy : public Strategy {
public:
    /**
     * @brief Executes the social welfare strategy.
     * 
     * This method defines the specific actions to be taken
     * by the government to enhance social welfare.
     * 
     * @param government A pointer to the Government object
     *                   that will utilize this strategy.
     */
    void executeStrategy(Government* government) override;
};

#endif // SOCIALWELFARESTRATEGY_H

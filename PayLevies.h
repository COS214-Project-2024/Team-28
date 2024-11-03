#ifndef PAYLEVIES_H
#define PAYLEVIES_H

#include "Command.h"
#include "CityManager.h"

/**
 * @class PayLevies
 * @brief Command for paying levies within the city management system.
 *
 * This class implements the Command interface and provides the functionality
 * to execute the action of paying levies by interacting with the CityManager.
 */
class PayLevies : public Command {
public:
    /**
     * @brief Constructs a PayLevies command.
     * @param cityManager Pointer to the CityManager that handles city operations.
     */
    PayLevies(CityManager* cityManager) : cityManager(cityManager) {}

    /**
     * @brief Executes the pay levies command.
     *
     * This method will carry out the logic necessary to process the payment
     * of levies within the city management system.
     */
    void execute() override;

private:
    CityManager* cityManager; ///< Pointer to the associated CityManager.
};

#endif // PAYLEVIES_H

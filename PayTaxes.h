#ifndef PAYTAXES_H
#define PAYTAXES_H

#include "Command.h"
#include "CityManager.h"

/**
 * @class PayTaxes
 * @brief Command for paying taxes within the city management system.
 *
 * This class implements the Command interface and provides the functionality
 * to execute the action of paying taxes by interacting with the CityManager.
 */
class PayTaxes : public Command {
public:
    /**
     * @brief Constructs a PayTaxes command.
     * @param cityManager Pointer to the CityManager that handles city operations.
     */
    PayTaxes(CityManager* cityManager) : cityManager(cityManager) {}

    /**
     * @brief Executes the pay taxes command.
     *
     * This method will carry out the logic necessary to process the payment
     * of taxes within the city management system.
     */
    void execute() override;

private:
    CityManager* cityManager; ///< Pointer to the associated CityManager.
};

#endif // PAYTAXES_H

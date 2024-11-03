#ifndef OPERATIONAL_H
#define OPERATIONAL_H

#include "PowerPlantState.h"

/**
 * @class Operational
 * @brief Class representing the operational state of the power plant.
 *
 * This class inherits from the PowerPlantState interface, representing the state 
 * when the power plant is functioning normally. It may include methods and 
 * properties relevant to the operational status of the plant.
 */
class Operational : public PowerPlantState
{
private:
    // Private data members related to the operational state can be added here.

public:
    /**
     * @brief Default constructor for the Operational class.
     */
    Operational();

    /**
     * @brief Destructor for the Operational class.
     */
    ~Operational();
};

#endif // OPERATIONAL_H

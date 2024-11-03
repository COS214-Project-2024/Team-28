#ifndef OPERATING_H
#define OPERATING_H

#include "WastePlantState.h"

/**
 * @class Operating
 * @brief Class representing the operating state of the waste plant.
 *
 * This class inherits from the WastePlantState interface, representing the state 
 * when the waste plant is actively processing waste. It may implement specific
 * behaviors or methods related to the operational phase of the plant.
 */
class Operating : public WastePlantState
{
    // Future functionality specific to the Operating state can be added here.
};

#endif // OPERATING_H

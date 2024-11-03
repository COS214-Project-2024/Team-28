#ifndef OVERLOAD_H
#define OVERLOAD_H

#include "PowerPlantState.h"

/**
 * @class Overload
 * @brief Represents the overload state of the power plant.
 *
 * This class inherits from the PowerPlantState interface and encapsulates
 * the behavior and properties relevant to the power plant when it is
 * operating beyond its safe capacity.
 */
class Overload : public PowerPlantState
{
public:
    // Additional methods and attributes can be added here as needed.
};

#endif // OVERLOAD_H

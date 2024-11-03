// Dependent.h
#ifndef DEPENDENT_H
#define DEPENDENT_H

#include "Citizen.h"

/**
 * @class Dependent
 * @brief Represents a dependent citizen.
 *
 * The Dependent class inherits from the Citizen class and
 * represents a citizen who is dependent, potentially lacking
 * certain responsibilities like tax payment or housing ownership.
 */
class Dependent : public Citizen {
public:
    /**
     * @brief Constructs a new Dependent object.
     *
     * @param government A pointer to the Government instance this dependent interacts with.
     * @param isHouseOwner A boolean indicating if the dependent is a house owner.
     */
    Dependent(Government* government, bool isHouseOwner);
};

#endif // DEPENDENT_H

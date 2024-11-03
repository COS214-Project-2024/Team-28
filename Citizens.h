#include <exception>
using namespace std;

#ifndef __Citizens_h__
#define __Citizens_h__

// Forward declaration of classes to avoid circular dependencies
class CityManager; ///< Forward declaration of the CityManager class
class Citizen; ///< Forward declaration of the Citizen class
class PayTaxes; ///< Forward declaration of the PayTaxes class
class PayLevies; ///< Forward declaration of the PayLevies class
class CitizenIterator; ///< Forward declaration of the CitizenIterator class

/**
 * @class Citizens
 * @brief Manages a collection of Citizen objects.
 *
 * The Citizens class provides functionality to add and remove citizens,
 * as well as to obtain an iterator for iterating through the collection of citizens.
 */
class Citizens
{
public:
    CityManager* _unnamed_CityManager_; ///< Pointer to the associated CityManager.
    Citizen* _unnamed_Citizen_; ///< Pointer to a Citizen object.
    PayTaxes* _unnamed_PayTaxes_; ///< Pointer to a PayTaxes object.
    PayLevies* _unnamed_PayLevies_; ///< Pointer to a PayLevies object.

    /**
     * @brief Adds a Citizen to the collection.
     * @param aCitizen The Citizen object to be added.
     */
    void addCitizen(Citizen aCitizen);

    /**
     * @brief Removes a Citizen from the collection.
     * @param aCitizen The Citizen object to be removed.
     */
    void removeCitizen(Citizen aCitizen);

    /**
     * @brief Gets an iterator for the Citizens collection.
     * @return An iterator for traversing the Citizens.
     */
    CitizenIterator getIterator();
};

#endif // __Citizens_h__

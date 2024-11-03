#ifndef __PopulationManager_h__
#define __PopulationManager_h__

#include <exception>
#include "Citizen.h"

// Forward declarations
class HealthServices;
class CityManager;

/**
 * @class PopulationManager
 * @brief Manages the population within the city.
 *
 * The PopulationManager class is responsible for tracking the citizens,
 * managing population growth, and evaluating the employment status of 
 * the population. It interacts with health services and city management.
 */
class PopulationManager {
private:
    List<Citizen> _citizens; ///< List of citizens in the population manager.
    int _count;              ///< Total count of citizens.

public:
    HealthServices* _unnamed_HealthServices_; ///< Pointer to health services.
    CityManager* _unnamed_CityManager_;       ///< Pointer to city manager.

    /**
     * @brief Adds a citizen to the population manager.
     * @param aCitizen The citizen to be added.
     */
    void addCitizen(Citizen aCitizen);

    /**
     * @brief Removes a citizen from the population manager.
     * @param aCitizen The citizen to be removed.
     */
    void removeCitizen(Citizen aCitizen);

    /**
     * @brief Tracks the growth of the population.
     *
     * This method analyzes the current population and updates statistics 
     * related to population growth.
     */
    void trackPopulationGrowth();

    /**
     * @brief Evaluates the employment status of the population.
     *
     * This method checks the employment situation of the citizens 
     * and makes recommendations or changes if necessary.
     */
    void evaluateEmploymentStatus();
};

#endif // __PopulationManager_h__

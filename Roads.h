#ifndef ROADS_H
#define ROADS_H

#include "Services.h"
#include <string>

/**
 * @class Roads
 * @brief Represents road services within a city.
 *
 * This class manages the various services related to roads, including
 * repairs, lane expansions, and traffic regulation.
 */
class Roads : public Services {
public:
    Roads();

    /**
     * @brief Provides the necessary road services.
     */
    void provideService() override;

    /**
     * @brief Repairs the road.
     * 
     * This method includes the implementation details for repairing
     * the road infrastructure.
     */
    void repairRoad();

    /**
     * @brief Expands the number of lanes on the road.
     * 
     * @param numberOfLanes The number of lanes to add to the road.
     */
    void expandLanes(int numberOfLanes);

    /**
     * @brief Regulates traffic on the road.
     * 
     * This method includes the implementation details for traffic regulation,
     * such as controlling traffic lights and monitoring traffic flow.
     */
    void regulateTraffic();

private:
    std::string roadCondition; ///< The current condition of the road.
};

#endif // ROADS_H

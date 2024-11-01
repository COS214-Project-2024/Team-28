#ifndef ROADS_H
#define ROADS_H

#include "Services.h"
#include <string>

class Roads : public Services {
public:
    Roads();
    void provideService() override;
    void repairRoad();
    void expandLanes(int numberOfLanes);
    void regulateTraffic();

private:
    std::string roadCondition;
};

#endif // ROADS_H
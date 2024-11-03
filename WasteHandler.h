#ifndef WASTEHANDLER_H
#define WASTEHANDLER_H
#include <string>
#include "PlantStateHandler.h"
#include "WastePlant.h"
using namespace std;

class WasteHandler : public PlantStateHandler
{public:
 PowerHandler();                 // Default constructor
    virtual ~PowerHandler();        // Declare virtual destructor

    void handleRequest(PlantsManager* manager, const std::string& faultType) override;
};
#endif

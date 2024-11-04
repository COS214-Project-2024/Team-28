// PowerHandler.h
#ifndef POWERHANDLER_H
#define POWERHANDLER_H
#include "PlantStateHandler.h"


class PowerHandler : public PlantStateHandler {
public:
    PowerHandler();                 // Default constructor
    virtual ~PowerHandler();        // Declare virtual destructor

    void handleRequest(PlantsManager* manager, const std::string& faultType) override;
};

#endif // POWERHANDLER_H

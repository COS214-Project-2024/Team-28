#ifndef SEWAGEHANDLER_H
#define SEWAGEHANDLER_H
#include <string>
#include "PlantStateHandler.h"

class SewageHandler : public PlantStateHandler
{
public:
    SewageHandler();          // Default constructor
    virtual ~SewageHandler(); // Declare virtual destructor

    void handleRequest(PlantsManager *manager, const std::string &faultType) override;
};
#endif
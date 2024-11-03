#ifndef WATERHANDLER_H
#define WATERHANDLER_H
#include <string>
#include "PlantStateHandler.h"

class WaterHandler : public PlantStateHandler
{
public:
    WaterHandler();
    virtual ~WaterHandler();
    void handleRequest(PlantsManager *manager, const std::string &faultType) override;
};

#endif
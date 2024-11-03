// PlantStateHandler.h
#ifndef PLANTSTATEHANDLER_H
#define PLANTSTATEHANDLER_H

#include "FaultHandler.h"

class PlantStateHandler : public FaultHandler {
public:
    PlantStateHandler();
    virtual ~PlantStateHandler();

    // Override the handleRequest method
    void handleRequest(PlantsManager* manager, const std::string& faultType) override;
};

#endif // PLANTSTATEHANDLER_H

#ifndef PLANTSTATEHANDLER_H
#define PLANTSTATEHANDLER_H
#include "PlantsManager.h"


class PlantStateHandler {
public:
    PlantStateHandler():nextHandler(nullptr){}
    virtual ~PlantStateHandler();

    // Override the handleRequest method
    //void handleRequest(PlantsManager* manager, const std::string& faultType) override;
    void setNext(PlantStateHandler* handler) {
        nextHandler = handler;
    }

    virtual void handleRequest(PlantsManager* manager, const std::string& faultType) = 0;

protected:
    PlantStateHandler* nextHandler;

};

#endif // PLANTSTATEHANDLER_H

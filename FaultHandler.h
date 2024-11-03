// FaultHandler.h
#ifndef FAULTHANDLER_H
#define FAULTHANDLER_H

#include <string>

// Forward declaration to reduce dependencies
class PlantsManager;

class FaultHandler {
protected:
    FaultHandler* nextHandler; // Pointer to the next handler in the chain

public:
    FaultHandler() : nextHandler(nullptr) {}
    virtual ~FaultHandler(); // Virtual destructor

    // Set the next handler in the chain
    void setNext(FaultHandler* handler) {
        nextHandler = handler;
    }

    // Handle the fault or pass it to the next handler
    virtual void handleRequest(PlantsManager* manager, const std::string& faultType) = 0;
};

#endif // FAULTHANDLER_H

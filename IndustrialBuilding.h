// IndustrialBuilding.h
#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H

#include <string>

class IndustrialBuilding {
public:

    // Pure virtual methods
    virtual void construct() = 0;
    virtual void maintain() = 0;
    virtual void startProduction() = 0;
    virtual void stopProduction() = 0;
    virtual void hireWorker(const std::string& workerName) = 0;
    virtual void allocateJobs() = 0;
    virtual int getNumberOfWorkers() const = 0;
    virtual void print() const = 0;
};

#endif // INDUSTRIALBUILDING_H

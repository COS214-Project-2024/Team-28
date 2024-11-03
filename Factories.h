#ifndef FACTORIES_H
#define FACTORIES_H

#include <vector>
#include <iostream>
#include "Building.h"
#include "MaterialHub.h"
#include "IndustrialBuilding.h"

class Factories : public IndustrialBuilding {
private:
    MaterialHub* materialHub;
    std::vector<MaterialHub*> materials;
    std::vector<std::string> workers;
    bool isOperational;
    bool productionStatus;
    int maintenanceCount;
    int numberOfWorkers;

public:
    explicit Factories(MaterialHub* hub, const std::string& name = "Default Factory", const std::string& location = "Default Location", int capacity = 100);
    ~Factories();

    void construct() override;
    void maintain() override;
    void startProduction() override;
    void stopProduction() override;
    void hireWorker(const std::string& workerName) override;
    void allocateJobs() override;
    int getNumberOfWorkers() const override;
    void print() const override;

    bool isFactoryOperational() const;
    int getMaintenanceCount() const;

    // Implementing pure virtual functions from IndustrialBuilding
    void startOperation() override;
    void stopOperation() override;
    void performInspection() override;
    std::string getBuildingDetails() const override;
};

#endif // FACTORIES_H
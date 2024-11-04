#ifndef WATERPLANT_H
#define WATERPLANT_H
#include <string>
#include "WaterPlantState.h"
#include "Plant.h"

class WaterPlant : public Plant
{
private:
    std::string purificationLevel;
    int NumberofLitres;
public:
    WaterPlant(const std::string &name, const std::string &loc, int cap);
    ~WaterPlant();
    void startWaterTreatment();
    void distribureWater();
    void changePurificationLevel(std::string level);
    WaterPlantState* getWaterState(); 
    // Plant operations
    void startPlant() override;
    void stopPlant() override;
    void performMaintenance()override;
    std::string getPlantDetails() const override;
    void startOperation() override;
    void stopOperation() override;
    void performInspection() override;
    std::string getBuildingDetails() const override;

        // Implement missing pure virtual functions
    void print() const override;
    void construct() override;
    void maintain() override;
    void startProduction() override;
    void stopProduction() override;
    void hireWorker(const std::string& workerName) override;
    void allocateJobs() override;
    int getNumberOfWorkers() const override;
};
#endif

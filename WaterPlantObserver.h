
using namespace std;

#ifndef WaterPlantObserver_h
#define WaterPlantObserver_h

#include "PlantsManager.h"

// class PlantsManager;
class WaterPlantObserver;

class WaterPlantObserver: public PlantsManager
{

	void update() override;
};

#endif


using namespace std;

#ifndef WastePlantObserver_h
#define WastePlantObserver_h

#include "PlantsManager.h"

// class PlantsManager;
class WastePlantObserver;

class WastePlantObserver: public PlantsManager
{

	public: void update() override;
};

#endif


using namespace std;

#ifndef SewagePlantObserver_h
#define SewagePlantObserver_h
#include "PlantsManager.h"

// class PlantsManager;
class SewwagePlantObserver;

class SewwagePlantObserver: public PlantsManager
{
	public:
	 void update() override;
};

#endif

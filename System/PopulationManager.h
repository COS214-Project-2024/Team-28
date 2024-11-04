#include <exception>
using namespace std;

#ifndef __PopulationManager_h__
#define __PopulationManager_h__

#include "Citizen.h"
// #include "HealthServices.h"
// #include "CityManager.h"

class Citizen;
class HealthServices;
class CityManager;
class PopulationManager;

class PopulationManager
{
	private: List<Citizen> _citizens;
	private: int _count;
	public: HealthServices* _unnamed_HealthServices_;
	public: CityManager* _unnamed_CityManager_;

	public: void addCitizen(Citizen aCitizen);

	public: void removeCitizen(Citizen aCitizen);

	public: void trackPopulationGrowth();

	public: void evaluateEmploymentStatus();
};

#endif

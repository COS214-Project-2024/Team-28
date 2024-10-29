#include <exception>
using namespace std;

#ifndef __EconomicGrowthStrategy_h__
#define __EconomicGrowthStrategy_h__

#include "Government.h"
// #include "BuildingFactory.h"
#include "Strategy.h"

class Government;
class BuildingFactory;
// class Strategy;
class EconomicGrowthStrategy;

class EconomicGrowthStrategy: public Strategy
{

	public: void() executeStrategy(Government aGovernment);

	public: void incentivizeBusinesses();

	public: void lowerCorporateTaxes();

	public: void addBusinesses(BuildingFactory* aNewbuilding);
};

#endif

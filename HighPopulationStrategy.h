#include <exception>
using namespace std;

#ifndef __HighPopulationStrategy_h__
#define __HighPopulationStrategy_h__

#include "Government.h"
#include "Strategy.h"

class Government;
// class Strategy;
class HighPopulationStrategy;

class HighPopulationStrategy: public Strategy
{

	public: void executeStrategy(Government aGovernment);

	public: void expandResidentialInfrastructure();

	public: void incentivizeEmploymentGrowth();

	public: void improveTransportationNetwork();

	public: void manageUtilityDemand();
};

#endif

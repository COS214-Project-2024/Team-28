#include <exception>
using namespace std;

#ifndef __Government_h__
#define __Government_h__

// #include "Command.h"
// #include "Strategy.h"
#include "Citizen.h"

class Command;
class Strategy;
class Citizen;
class Government;

class Government
{
	private: double _budget;
	private: double _taxRate;
	private: String _cityPolicies[];
	private: String _publicServices[];
	public: Command* _unnamed_Command_;
	public: Strategy* _unnamed_Strategy_;

	public: void setTaxRate(double aRate);

	public: void collectTaxes(List<Citizen> aCitizens);

	public: void allocateBudget(String aDepartment, double aAmount);

	public: void createPolicy(String aPolicyName);

	public: void evaluateCitizenNeeds(List<Citizen> aCitizens);

	public: void registerObserver(Observer aObserver);

	public: void notifyObservers();
};

#endif

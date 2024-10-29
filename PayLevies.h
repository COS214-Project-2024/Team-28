#include <exception>
using namespace std;

#ifndef __PayLevies_h__
#define __PayLevies_h__

#include "Citizens.h"
// #include "CityManager.h"
#include "Citizen.h"
#include "Command.h"

class Citizens;
class CityManager;
class Citizen;
// class Command;
class PayLevies;

class PayLevies: public Command
{
	public: Citizens* _unnamed_Citizens_;
	public: CityManager* _unnamed_CityManager_;

	public: void calculateLevies(Citizen aCitizen);

	public: void collectLevies(Citizens aArray);
};

#endif

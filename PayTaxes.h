#include <exception>
using namespace std;

#ifndef __PayTaxes_h__
#define __PayTaxes_h__

// #include "Citizens.h"
// #include "CityManager.h"
#include "Citizen.h"
#include "Command.h"

class Citizens;
class CityManager;
class Citizen;
// class Command;
class PayTaxes;

class PayTaxes: public Command
{
	public: Citizens* _unnamed_Citizens_;
	public: CityManager* _unnamed_CityManager_;

	public: void() calculateTax(Citizen aCitizen);

	public: void collectTax(Citizen aCitizen);
};

#endif

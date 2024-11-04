#include <exception>
using namespace std;

#ifndef __Citizens_h__
#define __Citizens_h__

// #include "CityManager.h"
#include "Citizen.h"
// #include "PayTaxes.h"
// #include "PayLevies.h"

class CityManager;
class Citizen;
class PayTaxes;
class PayLevies;
class Citizens;

class Citizens
{
	public: CityManager* _unnamed_CityManager_;
	public: Citizen* _unnamed_Citizen_;
	public: PayTaxes* _unnamed_PayTaxes_;
	public: PayLevies* _unnamed_PayLevies_;

	public: void addCitizen(Citizen aCitizen);

	public: void removeCitizen(Citizen aCitizen);

	public: CitizenIterator getIterator();
};

#endif

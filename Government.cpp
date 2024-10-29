#include <exception>
using namespace std;

#include "Government.h"
#include "Command.h"
#include "Strategy.h"
#include "Citizen.h"

void Government::setTaxRate(double aRate) {
	this->_taxRate = aRate;
}

void Government::collectTaxes(List<Citizen> aCitizens) {
	throw "Not yet implemented";
}

void Government::allocateBudget(String aDepartment, double aAmount) {
	throw "Not yet implemented";
}

void Government::createPolicy(String aPolicyName) {
	throw "Not yet implemented";
}

void Government::evaluateCitizenNeeds(List<Citizen> aCitizens) {
	throw "Not yet implemented";
}

void Government::registerObserver(Observer aObserver) {
	throw "Not yet implemented";
}

void Government::notifyObservers() {
	throw "Not yet implemented";
}


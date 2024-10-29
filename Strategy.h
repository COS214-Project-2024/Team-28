#include <exception>
using namespace std;

#ifndef __Strategy_h__
#define __Strategy_h__

#include "Government.h"

class Government;
class Strategy;

__abstract class Strategy
{
	public: Government* _unnamed_Government_;

	public: void() executeStrategy(Government aGovernment);
};

#endif

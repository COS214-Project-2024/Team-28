#include <exception>
using namespace std;

#ifndef __SocialWelfareStrategy_h__
#define __SocialWelfareStrategy_h__

#include "Government.h"
#include "Strategy.h"

class Government;
// class Strategy;
class SocialWelfareStrategy;

class SocialWelfareStrategy: public Strategy
{

	public: void executeStrategy(Government aGovernment);

	public: void increaseHealthcareBudget();

	public: void subsidizeEducation();
};

#endif

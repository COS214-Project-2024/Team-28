#ifndef SOCIALWELFARESTRATEGY_H
#define SOCIALWELFARESTRATEGY_H

#include "Strategy.h"
#include "Government.h"

class SocialWelfareStrategy : public Strategy {
public:
    void executeStrategy(Government* government) override;
};

#endif // SOCIALWELFARESTRATEGY_H
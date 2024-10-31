#ifndef SEWAGEPLANTOPERATIONALSTATE_H
#define SEWAGEPLANTOPERATIONALSTATE_H
#include "SewagePlantState.h"

class SewagePlantOperationalSate : public SewagePlantState
{
private:
    bool isOperational;
public:
    SewagePlantOperationalSate(/* args */);
    ~SewagePlantOperationalSate();
    void handleSewageState() override;
    void setOperational(bool operational);
};
#endif
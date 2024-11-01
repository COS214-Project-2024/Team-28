#ifndef SEWAGEPLANTFAILURESTATE_H
#define SEWAGEPLANTFAILURESTATE_H

#include "SewagePlantState.h"

class SewagePlantFailureState : public SewagePlantState
{
    private:
        bool isFailed;
    public:
        SewagePlantFailureState(bool isFailed);
        void handleSewageState() override;
        SewagePlantFailureState();
};
#endif
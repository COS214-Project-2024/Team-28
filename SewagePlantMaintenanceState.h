#ifndef SEWAGEPLANTMAINTENANCESTATE_H
#define SEWAGEPLANTMAINTENANCESTATE_H
#include "SewagePlantState.h"
#include "SewagePlantOperationalSate.h"

class SewagePlantMaintenanceState: public SewagePlantState
{
    private:
        SewagePlantOperationalSate *operationalState;
    public:
        SewagePlantMaintenanceState();
        void handleSewageState() override;
        ~SewagePlantMaintenanceState();
};
#endif
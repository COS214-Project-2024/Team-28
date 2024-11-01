#ifndef WASTEPLANTMAINTENANCESTATE_H
#define WASTEPLANTMAINTENANCESTATE_H
#include "WastePlantState.h"
#include "WastePlantOperationalState.h"

class WastePlantMaintenanceState: public WastePlantState
{
private:
    WastePlantOperationalState *operationalState;
public:
    WastePlantMaintenanceState(/* args */);
    ~WastePlantMaintenanceState();
  //  void handleWasteState() override;
     void handleState(Plant* plant) override;
    std::string getStateName() const override { return "PartialState"; }
};
#endif

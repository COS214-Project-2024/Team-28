#ifndef WASTEPLANTOPERATIONALSTATE_H
#define WASTEPLANTOPERATIONALSTATE_H
#include "WastePlantState.h"

class WastePlantOperationalState : public WastePlantState 
{
private:
    bool isOperational;
public:
    WastePlantOperationalState(/* args */){
        
    };
    ~WastePlantOperationalState();
    void setOperational(bool operational);
    virtual void handleState(Plant* plant) override;
    virtual std::string getStateName() const override;
};
#endif

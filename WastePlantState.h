#ifndef WASTEPLANTSTATE_H
#define WASTEPLANTSTATE_H

class WastePlantState
{
private:

    /* data */
public:
    WastePlantState(/* args */);
    ~WastePlantState();
    virtual void handleWasteState() = 0;
};
#endif


// WastePlantState::WastePlantState(/* args */)
// {
// }


// WastePlantState::~WastePlantState()
// {
// }


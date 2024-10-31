#ifndef SEWAGEPLANTSTATE_H
#define SEWAGEPLANTSTATE_H

class SewagePlantState
{
private:
    /* data */
public:
    SewagePlantState(/* args */);
    ~SewagePlantState();
    virtual void handleSewageState() = 0;
};
#endif

// SewagePlantState::SewagePlantState(/* args */)
// {
// }

// SewagePlantState::~SewagePlantState()
// {
// }

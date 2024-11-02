#ifndef PLANTSTATEHANDLER_H
#define PLANTSTATEHANDLER_H
#include <string>
using namespace std;

class PlantStateHandler
{
private:
    string fault;
    string plantName;
public:
    PlantStateHandler(/* args */);
    ~PlantStateHandler();
    void initiateFaultHandling(string faultType);
    virtual void restorePlantOperations() = 0;
    virtual void performRoutineMaintenance() = 0;
    virtual void changeState(string newState) = 0;
};
#endif

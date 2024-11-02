#ifndef DEPENDENT_H
#define DEPENDENT_H

#include "Citizen.h"

class Dependent : public Citizen {
public:
    Dependent(Government* government, bool isHouseOwner);
};

#endif // DEPENDENT_H
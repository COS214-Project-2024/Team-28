#ifndef WORKER_H
#define WORKER_H

#include "Citizen.h"

class Worker : public Citizen {
public:
    Worker(Government* government, bool isHouseOwner, double salary);
    double payTaxes() const override;

private:
    double salary;
};

#endif // WORKER_H
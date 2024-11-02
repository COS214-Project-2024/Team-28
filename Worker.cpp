#include "Worker.h"

Worker::Worker(Government* government, bool isHouseOwner, double salary) : Citizen(government, isHouseOwner), salary(salary) {}

double Worker::payTaxes() const {
    return salary * 0.05; // 5% tax on salary
}
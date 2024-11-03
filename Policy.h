// Policy.h
#ifndef POLICY_H
#define POLICY_H

#include <string>

struct Policy {
    std::string name;
    double impactFactor; // Determines how much the policy affects utility demands or fault probabilities
};

#endif // POLICY_H

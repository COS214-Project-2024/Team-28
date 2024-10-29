#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
//PRODUCT

class Building{
    public:
        Building() = default;
        ~Building() = default;
        virtual void print() const = 0;

};


#endif
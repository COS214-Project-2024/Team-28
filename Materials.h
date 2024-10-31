#ifndef MATERIALS_H
#define MATERIALS_H

#include <iostream>

// Base materials
class Steel {
public:
    virtual ~Steel() = default;
    virtual void process() = 0;
};

class Concrete {
public:
    virtual ~Concrete() = default;
    virtual void mix() = 0;
};

class Wood {
public:
    virtual ~Wood() = default;
    virtual void cut() = 0;
};

class SteelMaterial : public Steel {
public:
    void process() override {
        std::cout << "Processing steel...\n";
    }
};

class ConcreteMaterial : public Concrete {
public:
    void mix() override {
        std::cout << "Mixing concrete...\n";
    }
};

class WoodMaterial : public Wood {
public:
    void cut() override {
        std::cout << "Cutting wood...\n";
    }
};

#endif // MATERIALS_H
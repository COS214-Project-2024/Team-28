#ifndef MATERIALS_H
#define MATERIALS_H

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

#endif // MATERIALS_H
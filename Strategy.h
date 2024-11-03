// Strategy.h
#ifndef STRATEGY_H
#define STRATEGY_H

class Government;

class Strategy {
public:
    virtual void executeStrategy(Government* government) = 0;
    virtual ~Strategy() = default;
};

#endif // STRATEGY_H
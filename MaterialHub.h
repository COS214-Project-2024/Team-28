#ifndef MATERIALHUB_H
#define MATERIALHUB_H

#include "Materials.h"

// MaterialHub (Facade)
class MaterialHub {
public:
    virtual ~MaterialHub() = default;
    virtual Steel* createSteel() = 0;
    virtual Concrete* createConcrete() = 0;
    virtual Wood* createWood() = 0;
};

// Concrete MaterialHub builders
class SteelBuilder : public MaterialHub {
public:
    Steel* createSteel() override;
    Concrete* createConcrete() override;
    Wood* createWood() override;
};

class ConcreteBuilder : public MaterialHub {
public:
    Steel* createSteel() override;
    Concrete* createConcrete() override;
    Wood* createWood() override;
};

class WoodMaker : public MaterialHub {
public:
    Steel* createSteel() override;
    Concrete* createConcrete() override;
    Wood* createWood() override;
};

#endif // MATERIALHUB_H
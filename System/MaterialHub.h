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
    Steel* createSteel() override {
        return new SteelMaterial();
    }
    
    Concrete* createConcrete() override {
        return new ConcreteMaterial();
    }
    
    Wood* createWood() override {
        return new WoodMaterial();
    }
};

class ConcreteBuilder : public MaterialHub {
public:
    Steel* createSteel() override {
        return new SteelMaterial();
    }
    
    Concrete* createConcrete() override {
        return new ConcreteMaterial();
    }
    
    Wood* createWood() override {
        return new WoodMaterial();
    }
};

class WoodMaker : public MaterialHub {
public:
    Steel* createSteel() override {
        return new SteelMaterial();
    }
    
    Concrete* createConcrete() override {
        return new ConcreteMaterial();
    }
    
    Wood* createWood() override {
        return new WoodMaterial();
    }
};

#endif // MATERIALHUB_H
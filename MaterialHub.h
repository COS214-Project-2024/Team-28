#ifndef MATERIALHUB_H
#define MATERIALHUB_H

#include "Materials.h"

/**
 * @class MaterialHub
 * @brief Abstract interface for creating different building materials.
 *
 * The MaterialHub class serves as a facade for creating various building materials.
 * It defines the interface for creating Steel, Concrete, and Wood objects. Concrete
 * implementations of this interface are responsible for the actual instantiation
 * of these materials.
 */
class MaterialHub {
public:
    virtual ~MaterialHub() = default;

    /**
     * @brief Creates a Steel material.
     * @return A pointer to the newly created Steel object.
     */
    virtual Steel* createSteel() = 0;

    /**
     * @brief Creates a Concrete material.
     * @return A pointer to the newly created Concrete object.
     */
    virtual Concrete* createConcrete() = 0;

    /**
     * @brief Creates a Wood material.
     * @return A pointer to the newly created Wood object.
     */
    virtual Wood* createWood() = 0;
};

/**
 * @class SteelBuilder
 * @brief Concrete implementation of MaterialHub for creating Steel.
 *
 * The SteelBuilder class implements the MaterialHub interface and is responsible for
 * creating Steel, Concrete, and Wood materials.
 */
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

/**
 * @class ConcreteBuilder
 * @brief Concrete implementation of MaterialHub for creating Concrete.
 *
 * The ConcreteBuilder class implements the MaterialHub interface and is responsible for
 * creating Steel, Concrete, and Wood materials.
 */
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

/**
 * @class WoodMaker
 * @brief Concrete implementation of MaterialHub for creating Wood.
 *
 * The WoodMaker class implements the MaterialHub interface and is responsible for
 * creating Steel, Concrete, and Wood materials.
 */
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

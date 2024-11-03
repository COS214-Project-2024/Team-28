#ifndef MATERIALS_H
#define MATERIALS_H

#include <iostream>

/**
 * @class Steel
 * @brief Abstract base class for Steel materials.
 *
 * This class provides an interface for processing steel. Derived classes must implement
 * the process method.
 */
class Steel {
public:
    virtual ~Steel() = default;

    /**
     * @brief Processes the steel material.
     *
     * This pure virtual function must be implemented by derived classes to provide specific
     * processing logic for steel materials.
     */
    virtual void process() = 0;
};

/**
 * @class Concrete
 * @brief Abstract base class for Concrete materials.
 *
 * This class provides an interface for mixing concrete. Derived classes must implement
 * the mix method.
 */
class Concrete {
public:
    virtual ~Concrete() = default;

    /**
     * @brief Mixes the concrete material.
     *
     * This pure virtual function must be implemented by derived classes to provide specific
     * mixing logic for concrete materials.
     */
    virtual void mix() = 0;
};

/**
 * @class Wood
 * @brief Abstract base class for Wood materials.
 *
 * This class provides an interface for cutting wood. Derived classes must implement
 * the cut method.
 */
class Wood {
public:
    virtual ~Wood() = default;

    /**
     * @brief Cuts the wood material.
     *
     * This pure virtual function must be implemented by derived classes to provide specific
     * cutting logic for wood materials.
     */
    virtual void cut() = 0;
};

/**
 * @class SteelMaterial
 * @brief Concrete class for Steel material implementation.
 *
 * This class implements the Steel interface and provides a specific implementation for
 * processing steel.
 */
class SteelMaterial : public Steel {
public:
    void process() override {
        std::cout << "Processing steel...\n";
    }
};

/**
 * @class ConcreteMaterial
 * @brief Concrete class for Concrete material implementation.
 *
 * This class implements the Concrete interface and provides a specific implementation for
 * mixing concrete.
 */
class ConcreteMaterial : public Concrete {
public:
    void mix() override {
        std::cout << "Mixing concrete...\n";
    }
};

/**
 * @class WoodMaterial
 * @brief Concrete class for Wood material implementation.
 *
 * This class implements the Wood interface and provides a specific implementation for
 * cutting wood.
 */
class WoodMaterial : public Wood {
public:
    void cut() override {
        std::cout << "Cutting wood...\n";
    }
};

#endif // MATERIALS_H

#ifndef POWERPLANTSTATE_H
#define POWERPLANTSTATE_H

/**
 * @class PowerPlantState
 * @brief Abstract base class representing the state of a power plant.
 *
 * This class serves as the base for defining various states of a power plant,
 * such as operational, overload, or maintenance states. It provides a common
 * interface for all concrete state classes.
 */
class PowerPlantState {
private:
    /* data - can be used for state-specific information */
public:
    /**
     * @brief Default constructor for PowerPlantState.
     * 
     * This constructor initializes the state of the power plant.
     */
    PowerPlantState(/* args */);

    /**
     * @brief Destructor for PowerPlantState.
     * 
     * This destructor cleans up any resources used by the state.
     */
    virtual ~PowerPlantState();
};

#endif // POWERPLANTSTATE_H

#ifndef CITIZEN_H
#define CITIZEN_H

class Government; // Forward declaration of the Government class

/**
 * @class Citizen
 * @brief Represents a citizen with various attributes and actions in relation to government.
 *
 * The Citizen class encapsulates the properties and behaviors of a citizen, including 
 * tax payment, food hamper reception, satisfaction management, and strike actions.
 */
class Citizen {
public:
    /**
     * @brief Constructs a Citizen object.
     * @param government Pointer to the Government object associated with the citizen.
     * @param isHouseOwner Indicates whether the citizen is a house owner.
     */
    Citizen(Government* government, bool isHouseOwner);

    /**
     * @brief Calculates the taxes to be paid by the citizen.
     * @return The amount of taxes to be paid.
     */
    virtual double payTaxes() const;

    /**
     * @brief Receives a food hamper.
     */
    void receiveFoodHamper();

    /**
     * @brief Receives a specified amount of money.
     * @param amount The amount of money to receive.
     */
    void receiveMoney(double amount);

    /**
     * @brief Acknowledges the receipt of a grant.
     */
    void acknowledgeGrant();

    /**
     * @brief Updates the satisfaction level of the citizen.
     */
    void updateSatisfaction();

    /**
     * @brief Gets the current satisfaction level of the citizen.
     * @return The satisfaction level as an integer.
     */
    int getSatisfaction() const;

    /**
     * @brief Initiates a strike action.
     */
    void strike();

    /**
     * @brief Stops the strike action.
     */
    void stopStriking();

    /**
     * @brief Checks if the citizen is currently striking.
     * @return True if the citizen is striking, false otherwise.
     */
    bool isStriking() const;

    /**
     * @brief Sets the satisfaction level of the citizen.
     * @param satisfaction The new satisfaction level.
     */
    void setSatisfaction(int satisfaction);

    /**
     * @brief Checks if the citizen is a house owner.
     * @return True if the citizen owns a house, false otherwise.
     */
    bool isHouseOwner() const;

protected:
    int satisfaction; ///< The satisfaction level of the citizen.
    Government* government; ///< Pointer to the associated Government object.
    bool striking; ///< Indicates whether the citizen is currently striking.
    bool houseOwner; ///< Indicates whether the citizen is a house owner.
};

#endif // CITIZEN_H

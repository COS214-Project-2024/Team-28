// Government.h
#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <vector>
#include <string>
#include "Command.h"
#include "Strategy.h"
#include "Citizen.h"
#include "Worker.h"

/**
 * @class Government
 * @brief Represents the government that manages citizens, policies, and economic strategies.
 *
 * The Government class is responsible for setting tax rates, collecting taxes, 
 * allocating budgets, creating policies, and implementing strategies to 
 * manage the economy and citizen welfare.
 */
class Government {
public:
    /**
     * @brief Constructs a Government object.
     */
    Government();

    /**
     * @brief Sets the tax rate for citizens.
     *
     * @param rate The tax rate to be set.
     */
    void setTaxRate(double rate);

    /**
     * @brief Gets the current tax rate.
     *
     * @return The current tax rate.
     */
    double getTaxRate() const;

    /**
     * @brief Collects taxes from the specified citizens.
     *
     * @param citizens A vector of citizens from whom taxes will be collected.
     */
    void collectTaxes(const std::vector<Citizen>& citizens);

    /**
     * @brief Allocates a budget to a specific department.
     *
     * @param department The name of the department to allocate the budget to.
     * @param amount The amount of budget to allocate.
     */
    void allocateBudget(const std::string& department, double amount);

    /**
     * @brief Creates a new policy.
     *
     * @param policyName The name of the policy to be created.
     */
    void createPolicy(const std::string& policyName);

    /**
     * @brief Evaluates the needs of the specified citizens.
     *
     * @param citizens A vector of citizens whose needs are to be evaluated.
     */
    void evaluateCitizenNeeds(const std::vector<Citizen>& citizens);

    /**
     * @brief Sets a command to be executed by the government.
     *
     * @param command Pointer to the command to be set.
     */
    void setCommand(Command* command);

    /**
     * @brief Executes the currently set command.
     */
    void executeCommand();

    /**
     * @brief Sets a strategy to be implemented by the government.
     *
     * @param strategy Pointer to the strategy to be set.
     */
    void setStrategy(Strategy* strategy);

    /**
     * @brief Executes the currently set strategy.
     */
    void executeStrategy();

    /**
     * @brief Reduces levies for the citizens.
     */
    void reduceLevies();

    /**
     * @brief Increases taxes and levies for the citizens.
     */
    void increaseTaxesAndLevies();

    /**
     * @brief Gets the list of citizens managed by the government.
     *
     * @return A vector of citizens.
     */
    std::vector<Citizen> getCitizens() const;

    /**
     * @brief Sets the citizens managed by the government.
     *
     * @param citizens A vector of citizens to be managed.
     */
    void setCitizens(const std::vector<Citizen>& citizens);

    /**
     * @brief Updates the economic situation based on various effects.
     *
     * @param policyEffect Effect of the policy change.
     * @param taxEffect Effect of the tax change.
     * @param economicEffect General economic effect.
     */
    void updateEconomicSituation(int policyEffect, int taxEffect, int economicEffect);

    /**
     * @brief Gets the current economic situation.
     *
     * @return The current economic situation value.
     */
    int getEconomicSituation() const;

    /**
     * @brief Manages the payment of taxes.
     */
    void payTaxes();

private:
    double budget; ///< The total budget allocated to the government.
    double taxRate; ///< The current tax rate imposed on citizens.
    std::vector<std::string> cityPolicies; ///< List of policies in effect in the city.
    std::vector<std::string> publicServices; ///< List of public services managed by the government.
    Command* command; ///< Current command set to be executed.
    Strategy* strategy; ///< Current strategy being implemented.
    std::vector<Citizen> citizens; ///< List of citizens managed by the government.
    int economicSituation; ///< Current economic situation value.
    int levyRate; ///< Current rate of levies imposed.
};

#endif // GOVERNMENT_H

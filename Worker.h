#ifndef WORKER_H
#define WORKER_H

#include "Citizen.h"

/**
 * @class Worker
 * @brief Represents a worker who is a citizen and can pay taxes.
 *
 * The Worker class inherits from the Citizen class and adds functionality
 * specific to workers, such as salary and tax payment.
 */
class Worker : public Citizen {
public:
    /**
     * @brief Constructs a Worker object.
     * @param government Pointer to the Government associated with the Worker.
     * @param isHouseOwner Indicates if the Worker owns a house.
     * @param salary The salary of the Worker.
     */
    Worker(Government* government, bool isHouseOwner, double salary);

    /**
     * @brief Calculates the taxes to be paid by the Worker.
     * @return The amount of taxes to be paid.
     */
    double payTaxes() const override;

private:
    double salary; ///< The salary of the Worker.
};

#endif // WORKER_H

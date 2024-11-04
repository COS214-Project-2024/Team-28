#include "SocialWelfareStrategy.h"
#include "Government.h"
#include "Citizen.h"
#include <vector>

void SocialWelfareStrategy::executeStrategy(Government* government) {
    // Provide free food hampers and money to citizens
    std::vector<Citizen> citizens = government->getCitizens();
    for (auto& citizen : citizens) {
        citizen.receiveFoodHamper();
        citizen.receiveMoney(500.0); // Example amount
		citizen.updateSatisfaction();
    }
}
#include "Roads.h"
#include <iostream>

Roads::Roads() : Services("Roads", 100) {}

void Roads::provideService() {
    std::cout << "Providing road services..." << std::endl;
}

void Roads::repairRoad() {
    std::cout << "Repairing road." << std::endl;
}

void Roads::expandLanes(int numberOfLanes) {
    std::cout << "Expanding lanes to " << numberOfLanes << " lanes." << std::endl;
}

void Roads::regulateTraffic() {
    std::cout << "Regulating traffic." << std::endl;
}
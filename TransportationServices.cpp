#include "TransportationServices.h"
#include <iostream>

TransportationServices::TransportationServices() : Services("Transportation", 100) {}

void TransportationServices::provideService() {
    std::cout << "Providing transportation services..." << std::endl;
}

void TransportationServices::addRoute(const std::string& routeName) {
    routes.push_back(routeName);
    std::cout << "Adding route: " << routeName << std::endl;
}

void TransportationServices::removeRoute(const std::string& routeName) {
    std::cout << "Removing route: " << routeName << std::endl;
}

void TransportationServices::scheduleMaintenance() {
    std::cout << "Scheduling maintenance for transportation services..." << std::endl;
}

void TransportationServices::handleTraffic() {
    std::cout << "Handling traffic for transportation services..." << std::endl;
}

void TransportationServices::manageSubsystems() {
    publicTransit.addVehicle("Bus");
    publicTransit.removeVehicle("Bus");
    publicTransit.announceDelay(10);

    trains.addTrain("Express Train");
    trains.removeTrain("Express Train");
    trains.scheduleTrain("City Route");
    trains.announceDelay(5);

    airports.addFlight("Flight 101");
    airports.removeFlight("Flight 101");
    airports.scheduleFlightMaintenance();

    roads.repairRoad();
    roads.expandLanes(2);
    roads.regulateTraffic();
}

PublicTransit* TransportationServices::getPublicTransit() {
    return &publicTransit;
}

Trains* TransportationServices::getTrains() {
    return &trains;
}

Airports* TransportationServices::getAirports() {
    return &airports;
}

Roads* TransportationServices::getRoads() {
    return &roads;
}

#include <iostream>
#include "BuildingFactory.h"
#include "LandMarkFactory.h"
#include "CommercialBuildingFactory.h"
#include "ResidentialBuildingFactory.h"


int main() {
    /*-----------------------PARKS-----------------------*/
    LandMarkFactory landmarkFactory;
    //Landmark* park = landmarkFactory.createPark();            //might need to delete default contructor 
    Park* p = new Park("123 Park Ave", "Central Park", "1858", 5);
    p->print();
   // Landmark* monument = landmarkFactory.createMonument();
    Monument* m = new Monument("456 Monument St", "Liberty Bell", "1753", "Bronze", 4);
    m->print();
   // Landmark* center = landmarkFactory.createCenters();
    Center* c = new Center("789 Center Rd", "Community Center", "2000", 3);
    c->print();

    // Clean up
    delete p;
    delete m;
    delete c;
    /*---------------------------------------------------*/

    /*-----------------------RESIDENTIAL-----------------------*/
    ResidentialBuildingFactory residentialFactory;
    House* newHouse = new House("somewhere", 18);
        newHouse->print();
        newHouse->getBuildCost();
    Flat* newFlat = new Flat("nowhere", 100);
        newFlat->print();
    TownHouse* newTH = new TownHouse("up", 4);
        newTH->print();
    Estate* newEstate = new Estate("down", 10, 25);
        newEstate->avergeResidentsPerUnit();
    /*---------------------------------------------------*/

    /*-----------------------COMMERCIAL-----------------------*/
    CommericalBuildingFactory cF;
    Shop* newShop = new Shop("bikini-bottom", "KrabbyPatty", "Resturant", 1);
        newShop->print();
    Office* newOffice = new Office("184 drive", "EASPORTS", "GAMING", 1);
        newOffice->print();
    Mall* newMall = new Mall("Midrand", "Mall of Africa ", 300);
        newMall->print();
    /*---------------------------------------------------*/
    return 0;
}

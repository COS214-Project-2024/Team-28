#ifndef RESIDENTIALBUILDINGS_H
#define RESIDENTIALBUILDINGS_H


//Concrete Products of the Residential Building Abstract Product 
//Houses, flats/apartments, townhouses, estates.


#include <iostream>
#include "Building.h"

class House: public ResidentialBuilding{

    public:
        House():ResidentialBuilding(){
            this->address = "";
            this->numberOfResidents = 0;
            this->buildingCost = 10;
        }
        House(std::string address, int numberOfResidents){
            this->address = address;
            this->numberOfResidents = numberOfResidents;
        }
        float getBuildCost(){
            return this->buildingCost;         // return building cost for comparisons 
        }
        ~House() = default;
        int getNumberOfResidents(){      //Get numberOfResidents for citizen count 
            return this->numberOfResidents;
        }
        std::string getAddress(){   //We dont want same adresses 
            return this->address;
        }

        void print() const override{
            std::cout<<"----------"<<std::endl;
            std::cout<<"House Details: "<<std::endl;
            std::cout<<"Address: "<<address<<std::endl;
            std::cout<<"Number Of Residents: "<<numberOfResidents<<std::endl;
            std::cout<<"----------"<<std::endl;
        }
    private:
        std::string address;               //address
        int numberOfResidents;                         //number of residents in house 
        float buildingCost;          //cost to build the house defult is 10 
    
    



};

class Flat:public ResidentialBuilding{
     public:
        Flat():ResidentialBuilding(){
            this->address = "";
            this->numberOfResidents = 0;
            this->buildingCost = 100;
        }
        Flat(std::string address, int numberOfResidents){
            this->address = address;
            this->numberOfResidents = numberOfResidents;
        }
        float getBuildCost(){
            return this->buildingCost;          // return building cost for comparisons 
        }
        ~Flat() = default;
        int getnumberOfResidents(){      //Get numberOfResidents for citizen count 
            return this->numberOfResidents;
        }
        std::string getAddress(){   //We dont want same adresses 
            return this->address;
        }

        void print() const override{
            std::cout<<"----------"<<std::endl;
            std::cout<<"Flat Details: "<<std::endl;
            std::cout<<"Address: "<<address<<std::endl;
            std::cout<<"Number Of Residents: "<<numberOfResidents<<std::endl;
            std::cout<<"----------"<<std::endl;
        }
    private:
        std::string address;               //address
        int numberOfResidents;                         //number of residents in house 
        float buildingCost;         //cost to build the house defult is 10 



};


class TownHouse: public ResidentialBuilding{
     public:
        TownHouse():ResidentialBuilding(){
            this->address = "";
            this->numberOfResidents = 0;
            this->buildingCost = 110;
        }
        TownHouse(std::string address, int numberOfResidents){
            this->address = address;
            this->numberOfResidents = numberOfResidents;
        }
        float getBuildCost(){
            return this->buildingCost;          // return building cost for comparisons 
        }
        ~TownHouse() = default;
        int getnumberOfResidents(){      //Get numberOfResidents for citizen count 
            return this->numberOfResidents;
        }
        std::string getAddress(){   //We dont want same adresses 
            return this->address;
        }

        void print() const override{
            std::cout<<"----------"<<std::endl;
            std::cout<<"Townhouse Details: "<<std::endl;
            std::cout<<"Address: "<<address<<std::endl;
            std::cout<<"Number Of Residents: "<<numberOfResidents<<std::endl;
            std::cout<<"----------"<<std::endl;
        }
    private:
        std::string address;               //address
        int numberOfResidents;             //number of residents in house 
        float buildingCost;        //cost to build the house defult is 10 





};


class Estate: public ResidentialBuilding{
    public:
        Estate():ResidentialBuilding(){
            this->address = "";
            this->numberOfUnits = 0;
            this->numberOfResidents = 0;
            this->buildingCost = 1000;
            
        }
        Estate(std::string address, int numberOfUnits, int numberOfResidents){
            this->address = address;
            this->numberOfUnits = numberOfUnits;
            this->numberOfResidents = numberOfResidents;
        }
        float getBuildCost(){
            return this->buildingCost;          // return building cost for comparisons 
        }
        ~Estate() = default;
        
        int getNumberOfResidents(){      //Get numberOfResidents for citizen count 
            return this->numberOfResidents;
        }
        int avergeResidentsPerUnit(){
            this->avgPerUnit = this->numberOfUnits/this->numberOfUnits;
            return this->avgPerUnit;
        }
        std::string getAddress(){   //We dont want same adresses 
            return this->address;
        }

        void print() const override{
            std::cout<<"----------"<<std::endl;
            std::cout<<"Estate Details: "<<std::endl;
            std::cout<<"Address: "<<address<<std::endl;
            std::cout<<"Number of Units: "<<numberOfUnits<<std::endl;
            std::cout<<"Number Of Residents: "<<numberOfResidents<<std::endl;
            std::cout<<"Avergae Number Of Residents per unit: "<<avgPerUnit<<std::endl;
            std::cout<<"----------"<<std::endl;
        }
        //fucntions should change if we want estate to be made up of houses and flats 
        //getNumbherOfResidenst and build cost will change 
    private:
        std::string address;               //address
        int numberOfUnits;                 //number of units in Estate
        int numberOfResidents;  
        int avgPerUnit;                       //number of residents in estate
        float buildingCost;         //cost to build the house defult is 10 

        //if we want an estate to be made up of other residential buildings instead of units
        /*  House* houses;
            Flats* flats;
            TownHouses* thouses;
            */




};

/*class ResidentialBuilding: public BuildingFactory{//Concrete Factory 
    public:
        ResidentialBuilding() : BuildingFactory(){}
        int updatenumberOfResidents(int newnumberOfResidents) const override{
            return newnumberOfResidents;
        }
        Building* createBuilding() const override{
            return new House();     //How to add it to return a new flat??

        }


        

};
*/

#endif


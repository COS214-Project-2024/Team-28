#ifndef LANDMARKS_H
#define LANDMARKS_H


//Concrete Products of the Residential Building Abstract Product 
//Houses, flats/apartments, townhouses, estates.


#include <iostream>
#include "Building.h"

class Park: public Landmark{
    
     public:
        Park():Landmark(){
            this->address = "";
            this->nameOfPark = "";
            this->dateEstablished = "";
            this->condition = 0;
            this->buildingCost = 90;
        }
        Park(std::string address, std::string nameOfPark, std::string date, int condition ){
            this->address = address;
            this->nameOfPark = nameOfPark;
            this->dateEstablished = date;
            this->condition = condition;
        }
        float getBuildCost(){
            return this->buildingCost;          // return building cost for comparisons 
        }
        ~Park() = default;
        int getCondition(){      //Get numberOfResidents for citizen count 
            return this->condition;
        }
    // we can remove getAddress? what purpose is this going to serve, also remove in other classes
        std::string getAddress(){   //We dont want same adresses 
            return this->address;
        }

        void print() const override{
            std::cout<<"----------"<<std::endl;
            std::cout<<"Park Details: "<<std::endl;
            std::cout<<"Name "<<nameOfPark<<std::endl;
            std::cout<<"Date Opened: "<<dateEstablished<<std::endl;
            std::cout<<"Condition: "<<condition<<std::endl;
            std::cout<<"Address: "<<address<<std::endl;
            std::cout<<"----------"<<std::endl;
        }
    private:
        std::string address;  
        std::string nameOfPark;        //address                        
        std::string dateEstablished;   //
        int condition;                 // if condition < 1, effect citizen satrisfication etc
        float buildingCost;          //cost to build the house defult is 10 




};


class Monument: public Landmark{
    
     public:
        Monument():Landmark(){
            this->location = "";
            this->nameOfMonument = "";
            this->dateEstablished = "";
            this->materialUsed = "";        //Place Holder
            this->condition = 0;
            this->buildingCost = 90;
        }
        Monument(std::string location, std::string nameOfMonument, std::string date, std::string material, int condition ){
            this->location = location;
            this->nameOfMonument = nameOfMonument;
            this->dateEstablished = date;
            this->materialUsed = material;
            this->condition = condition;
        }
        float getBuildCost(){
            return this->buildingCost;          // return building cost for comparisons 
        }
        ~Monument() = default;
        int getCondition(){      //Get numberOfResidents for citizen count 
            return this->condition;
        }
        /*we can remove getAddress? what purpose is this going to serve, also remove in other classes
        std::string getAddress(){   //We dont want same adresses 
            return this->location;
        }
        */
        void print() const override{
            std::cout<<"----------"<<std::endl;
            std::cout<<"Monument Details: "<<std::endl;
            std::cout<<"Name "<<nameOfMonument<<std::endl;
            std::cout<<"Date Created: "<<dateEstablished<<std::endl;
            std::cout<<"Material: "<<materialUsed<<std::endl;
            std::cout<<"Condition: "<<condition<<std::endl;
            std::cout<<"Location: "<<location<<std::endl;
            std::cout<<"----------"<<std::endl;
        }
    private:
        std::string location;  
        std::string nameOfMonument;        //address 
        std::string materialUsed;          //Place hoolder until we establiish materials                       
        std::string dateEstablished;   //
        int condition;                 // if condition < 1, effect citizen satrisfication etc
        float buildingCost;          //cost to build the house defult is 10 




};


class Center: public Landmark{
    
     public:
        Center():Landmark(){
            this->address = "";
            this->nameOfCenter = "";
            this->description = "";
            this->dateEstablished = "";
            this->condition = 0;
            this->buildingCost = 90;
        }
        Center(std::string address, std::string nameOfCenter, std::string date, int condition ){
            this->address = address;
            this->nameOfCenter = nameOfCenter;
            this->dateEstablished = date;
            this->condition = condition;
        }
        float getBuildCost(){
            return this->buildingCost;          // return building cost for comparisons 
        }
        ~Center() = default;
        int getCondition(){      //Get numberOfResidents for citizen count 
            return this->condition;
        }
        // we can remove getAddress? what purpose is this going to serve, also remove in other classes
    

        void print() const override{
            std::cout<<"----------"<<std::endl;
            std::cout<<"Park Details: "<<std::endl;
            std::cout<<"Name "<<nameOfCenter<<std::endl;
            std::cout<<"Description: "<<description<<std::endl;
            std::cout<<"Date Opened: "<<dateEstablished<<std::endl;
            std::cout<<"Condition: "<<condition<<std::endl;
            std::cout<<"Address: "<<address<<std::endl;
            std::cout<<"----------"<<std::endl;
        }
    private:
        std::string address;  
        std::string nameOfCenter;        //address       
        std::string description;                 
        std::string dateEstablished;   //
        int condition;                 // if condition < 1, effect citizen satrisfication etc
        float buildingCost;          //cost to build the house defult is 10 




};



#endif
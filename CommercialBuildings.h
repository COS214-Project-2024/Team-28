#ifndef COMMERCIALBUILDINGS_H
#define COMMERCIALBUILDINGS_H


//Concrete Products of the Commerical Building Abstract Product 
//Shops, offices, malls.


#include <iostream>
#include "Building.h"

class Shop: public CommercialBuilding{
    public:
     Shop():CommercialBuilding(){
            this->address = "";
            this->shopName = "";
            this->typeOfShop = "";
            this->shopSize = 0;
            this->buildingCost = 50;

        }
        Shop(std::string address, std::string shopName, std::string typeOfShop,int shopSize ){
            this->address = address;
            this->shopName = shopName;
            this->typeOfShop = typeOfShop;
            this->shopSize = shopSize;

        }
        float getBuildCost(){
            return this->buildingCost;          // return building cost for comparisons 
        }
        ~Shop() = default;
        int getSize(){
            return this->shopSize;
        }
        std::string getAddress(){   //We dont want same adresses 
            return this->address;
        }

        void print() const override{
            std::cout<<"----------"<<std::endl;
            std::cout<<"Shop Details: "<<std::endl;
            std::cout<<"Name: "<<shopName<<std::endl;
            std::cout<<"Type: "<<typeOfShop<<std::endl;
            std::cout<<"Address: "<<address<<std::endl;
            std::cout<<"Shop Size Category "<<shopSize<<std::endl;
            std::cout<<"----------"<<std::endl;
        }


    private:
        std::string address;
        std::string shopName;
        std::string typeOfShop;
        int shopSize;           // we will take taxes depoending on howw big the sie is, example shopSize 1 shops will pay 10, shopSize 2 will pay 20 etc
        float buildingCost;
};

class Office: public CommercialBuilding{
    public:
        Office():CommercialBuilding(){
            this->address = "";
            this->companyName = "";
            this->typeOfCompany = "";
            this->officeSize = 0;
            this->buildingCost = 70;

        }
        Office(std::string address, std::string companyName, std::string typeOfCompany,int officeSize ){
            this->address = address;
            this->companyName = companyName;
            this->typeOfCompany = typeOfCompany;
            this-> officeSize = officeSize;

        }
        float getBuildCost(){
            return this->buildingCost;          // return building cost for comparisons 
        }
        ~Office() = default;
        int getSize(){
            return this->officeSize;
        }
        std::string getAddress(){   //We dont want same adresses 
            return this->address;
        }

        void print() const override{
            std::cout<<"----------"<<std::endl;
            std::cout<<"Office Details: "<<std::endl;
            std::cout<<"Name: "<<companyName<<std::endl;
            std::cout<<"Type: "<<typeOfCompany<<std::endl;
            std::cout<<"Address: "<<address<<std::endl;
            std::cout<<"Office Size Category "<<officeSize<<std::endl;
            std::cout<<"----------"<<std::endl;
        }


    private:
        std::string address;
        std::string companyName;
        std::string typeOfCompany;
        int officeSize;           // we will take taxes depoending on howw big the sie is, example shopSize 1 shops will pay 10, shopSize 2 will pay 20 etc
        float buildingCost;
};


class Mall: public CommercialBuilding{
    public:
     Mall():CommercialBuilding(){
            this->address = "";
            this->mallName = "";
            this->numberOfStores = 0;
            this->buildingCost = 500;

        }
        Mall(std::string address, std::string mallName,int numberOfStores ){
            this->address = address;
            this->mallName = mallName;
            this->numberOfStores= numberOfStores;

        }
        float getBuildCost(){
            return this->buildingCost;          // return building cost for comparisons 
        }
        ~Mall() = default;
        int getSize(){
            return this->numberOfStores;
        }
        std::string getAddress(){   //We dont want same adresses 
            return this->address;
        }

        void print() const override{
            std::cout<<"----------"<<std::endl;
            std::cout<<"Mall Details: "<<std::endl;
            std::cout<<"Mall Name: "<<mallName<<std::endl;
            std::cout<<"Number of Stores: "<<numberOfStores<<std::endl;
            std::cout<<"Address: "<<address<<std::endl;
            std::cout<<"----------"<<std::endl;
        }
    /*
        if we want mall to be made up of shops and offices
         //getNumberOfUnits and buildCost will change 
    */


    private:
        std::string address;
        std::string mallName;
        int numberOfStores;           // we will take taxes depoending on howw big the sie is, example shopSize 1 shops will pay 10, shopSize 2 will pay 20 etc
        float buildingCost;
       
        //If we want a mall to be made up of diiferent shops and offices intead of stores
        /*
            Shop*  shops;
            Office* offices;
            */
};



#endif
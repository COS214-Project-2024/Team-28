#ifndef CITIZEN_H
#define CITIZEN_H

class Government;

class Citizen {
public:
    Citizen(Government* government, bool isHouseOwner);
    virtual double payTaxes() const;
    void receiveFoodHamper();
    void receiveMoney(double amount);
    void acknowledgeGrant();
    void updateSatisfaction();
    int getSatisfaction() const;
    void strike();
    void stopStriking();
    bool isStriking() const;
    void setSatisfaction(int satisfaction);
    bool isHouseOwner() const;

protected:
    int satisfaction;
    Government* government;
    bool striking;
    bool houseOwner;
};

#endif // CITIZEN_H
#ifndef CITIZEN_H
#define CITIZEN_H

class Government;

class Citizen {
public:
    Citizen(Government* government);
    double payTaxes(double taxRate) const;
    void receiveFoodHamper();
    void receiveMoney(double amount);
    void acknowledgeGrant();
    void updateSatisfaction();
    int getSatisfaction() const;
    void strike();
    void stopStriking();
    bool isStriking() const;
    void setSatisfaction(int satisfaction);

private:
    int satisfaction;
    Government* government;
    bool striking;
};

#endif // CITIZEN_H
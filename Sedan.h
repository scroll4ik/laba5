#ifndef SEDAN_H
#define SEDAN_H
#include "Passenger.h"

class Sedan : public Passenger {
private:
    double trunkVolume;
public:
    Sedan();
    Sedan(string b, int y, double p, int pc, double tv);
    Sedan(const Sedan& other);
    ~Sedan() override;

    double getTrunkVolume() const;
    void setTrunkVolume(double tv);

    double calculateTax() const;
    void printTableHeader() const override;

    friend istream& operator>>(istream& is, Sedan& s);
    friend ostream& operator<<(ostream& os, const Sedan& s);
};
#endif
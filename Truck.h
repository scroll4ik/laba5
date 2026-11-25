#ifndef TRUCK_H
#define TRUCK_H
#include "Freight.h"

class Truck : public Freight {
private:
    bool hasTrailer;
public:
    Truck();
    Truck(string b, int y, double p, double lc, bool ht);
    Truck(const Truck& other);
    ~Truck() override;

    bool getHasTrailer() const;
    void setHasTrailer(bool ht);

    double calculateTax() const;

    void printTableHeader() const override;

    friend istream& operator>>(istream& is, Truck& t);
    friend ostream& operator<<(ostream& os, const Truck& t);
};
#endif
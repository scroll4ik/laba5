#ifndef FREIGHT_H
#define FREIGHT_H
#include "Transport.h"

class Freight : public Transport {
protected:
    double loadCapacity;
public:
    Freight();
    Freight(string b, int y, double p, double lc);
    Freight(const Freight& other);
    ~Freight() override;

    double getLoadCapacity() const;
    void setLoadCapacity(double lc);

    double calculateTax() const;
    void printTableHeader() const override;

    friend istream& operator>>(istream& is, Freight& f);
    friend ostream& operator<<(ostream& os, const Freight& f);
};
#endif
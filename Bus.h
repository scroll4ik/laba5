#ifndef BUS_H
#define BUS_H
#include "Passenger.h"

class Bus : public Passenger {
private:
    int routeNumber;
public:
    Bus();
    Bus(string b, int y, double p, int pc, int rn);
    Bus(const Bus& other);
    ~Bus() override;

    int getRouteNumber() const;
    void setRouteNumber(int rn);

    double calculateTax() const;

    void printTableHeader() const override;

    friend istream& operator>>(istream& is, Bus& b);
    friend ostream& operator<<(ostream& os, const Bus& b);
};
#endif
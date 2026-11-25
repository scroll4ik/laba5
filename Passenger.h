#ifndef PASSENGER_H
#define PASSENGER_H
#include "Transport.h"

class Passenger : public Transport {
protected:
    int passengerCapacity;
public:
    Passenger();
    Passenger(string b, int y, double p, int pc);
    Passenger(const Passenger& other);
    ~Passenger() override;

    int getPassengerCapacity() const;
    void setPassengerCapacity(int pc);
    void printTableHeader() const override;
    double calculateTax() const;
    friend istream& operator>>(istream& is, Passenger& p);
    friend ostream& operator<<(ostream& os, const Passenger& p);
};
#endif
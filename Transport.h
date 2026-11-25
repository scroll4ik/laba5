#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

class Transport {
protected:
    string brand;
    int year;
    double price; 
public:
    Transport();
    Transport(string b, int y, double p);
    Transport(const Transport& other);
    virtual ~Transport();

    string getBrand() const;
    void setBrand(const string& b);
    int getYear() const;
    void setYear(int y);
    double getPrice() const;
    void setPrice(double p);
    virtual double calculateTax() const;

    virtual void printTableHeader() const;

    friend istream& operator>>(istream& is, Transport& t);
    friend ostream& operator<<(ostream& os, const Transport& t);
};
#endif
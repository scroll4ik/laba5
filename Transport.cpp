#include "Transport.h"
#include "SafeInput.h"

Transport::Transport() : brand("Unknown"), year(2000), price(0.0) {}
Transport::Transport(string b, int y, double p) : brand(b), year(y), price(p) {}
Transport::Transport(const Transport& other) : brand(other.brand), year(other.year), price(other.price) {}
Transport::~Transport() { cout << "   -> [Transport] Base part deleted.\n"; }

string Transport::getBrand() const { return brand; }
void Transport::setBrand(const string& b) { brand = b; }
int Transport::getYear() const { return year; }
void Transport::setYear(int y) { year = y; }
double Transport::getPrice() const { return price; }
void Transport::setPrice(double p) { price = p; }

double Transport::calculateTax() const {
    int age = 2024 - year;
    double baseTax = price * 0.05; // 5% от стоимости
    return baseTax + (age > 0 ? age * 50.0 : 0); // +50 баксов за каждый год старости
}

void Transport::printTableHeader() const {
    cout << left << setw(5) << "ID"
        << setw(12) << "Type"
        << "| " << setw(15) << "Brand"
        << "| " << setw(6) << "Year";
}

//istream& operator>>(istream& is, Transport& t) {
//    cout << "Enter brand: "; is >> t.brand;
//    cout << "Enter year: "; is >> t.year;
//    cout << "Enter price ($): "; is >> t.price;
//    return is;
//}
istream& operator>>(istream& is, Transport& t) {
    t.brand = inputOnlyLetters("Enter brand (letters only): ");
    t.year = inputInt("Enter year (1900-2026): ", 1900, 2026);
    t.price = inputDouble("Enter price ($): ", 0.0, 10000000.0);
    return is;
}

ostream& operator<<(ostream& os, const Transport& t) {
    os << left << setw(15) << t.brand << "| " << setw(6) << t.year << "| ";
    return os;
}
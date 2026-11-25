#include "Freight.h"

Freight::Freight() : Transport(), loadCapacity(0.0) {}
Freight::Freight(string b, int y, double p, double lc) : Transport(b, y, p), loadCapacity(lc) {}
Freight::Freight(const Freight& other) : Transport(other), loadCapacity(other.loadCapacity) {}
Freight::~Freight() { cout << "  -> [Freight] part deleted.\n"; }

double Freight::getLoadCapacity() const { return loadCapacity; }
void Freight::setLoadCapacity(double lc) { loadCapacity = lc; }


double Freight::calculateTax() const {
    return Transport::calculateTax() + (loadCapacity * 100.0); // +100 за каждую тонну
}

void Freight::printTableHeader() const {
    Transport::printTableHeader(); // Печатает ID, Type, Brand, Year
    cout << "| " << setw(15) << "Capacity"; // Добавляет свое
}

istream& operator>>(istream& is, Freight& f) {
    is >> static_cast<Transport&>(f);
    cout << "Enter capacity (tons): "; is >> f.loadCapacity;
    return is;
}

ostream& operator<<(ostream& os, const Freight& f) {
    os << static_cast<const Transport&>(f);
    os << setw(15) << (to_string(f.loadCapacity) + "t");
    return os;
}
#include "Truck.h"

Truck::Truck() : Freight(), hasTrailer(false) {}
Truck::Truck(string b, int y, double p, double lc, bool ht) : Freight(b, y, p, lc), hasTrailer(ht) {}
Truck::Truck(const Truck& other) : Freight(other), hasTrailer(other.hasTrailer) {}
Truck::~Truck() { cout << "[Truck] deleted.\n"; }

bool Truck::getHasTrailer() const { return hasTrailer; }
void Truck::setHasTrailer(bool ht) { hasTrailer = ht; }

double Truck::calculateTax() const {
    return Freight::calculateTax() + (hasTrailer ? 500.0 : 0.0);
}

void Truck::printTableHeader() const {
    cout << "\n======================================================================================================\n";
    Freight::printTableHeader(); 
    cout << "| " << setw(10) << "Trailer" << "| " << setw(10) << "Price" << "| Tax/Maint\n";
    cout << "------------------------------------------------------------------------------------------------------\n";
}

istream& operator>>(istream& is, Truck& t) {
    is >> static_cast<Freight&>(t);
    cout << "Has trailer? (1 - Yes, 0 - No): "; is >> t.hasTrailer;
    return is;
}

ostream& operator<<(ostream& os, const Truck& t) {
    os << left << setw(12) << "Truck" << "| ";
    os << static_cast<const Freight&>(t); // Выведет Brand, Year, Capacity
    os << "| " << setw(10) << (t.hasTrailer ? "Yes" : "No")
        << "| $" << setw(9) << t.price << "| $" << t.calculateTax();
    return os;
}
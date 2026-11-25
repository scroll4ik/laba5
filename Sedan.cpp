#include "Sedan.h"

Sedan::Sedan() : Passenger(), trunkVolume(0.0) {}
Sedan::Sedan(string b, int y, double p, int pc, double tv) : Passenger(b, y, p, pc), trunkVolume(tv) {}
Sedan::Sedan(const Sedan& other) : Passenger(other), trunkVolume(other.trunkVolume) {}
Sedan::~Sedan() { cout << "[Sedan] deleted.\n"; }

double Sedan::getTrunkVolume() const { return trunkVolume; }
void Sedan::setTrunkVolume(double tv) { trunkVolume = tv; }

double Sedan::calculateTax() const {
    // Берем налог из Passenger (который берет из Transport) и добавляем копейки за объем багажника
    return Passenger::calculateTax() + (trunkVolume * 0.1);
}

void Sedan::printTableHeader() const {
    cout << "\n======================================================================================================\n";
    Passenger::printTableHeader(); // Выведет ID, Type, Brand, Year, Passengers
    cout << "| " << setw(10) << "Trunk (L)" << "| " << setw(10) << "Price" << "| Tax/Maint\n";
    cout << "------------------------------------------------------------------------------------------------------\n";
}



istream& operator>>(istream& is, Sedan& s) {
    is >> static_cast<Passenger&>(s);
    cout << "Enter trunk volume (liters): "; is >> s.trunkVolume;
    return is;
}

ostream& operator<<(ostream& os, const Sedan& s) {
    os << left << setw(12) << "Sedan" << "| ";
    os << static_cast<const Passenger&>(s); 
    os << "| " << setw(10) << s.trunkVolume
        << "| $" << setw(9) << s.price << "| $" << s.calculateTax();
    return os;
}
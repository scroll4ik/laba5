#include "Bus.h"

Bus::Bus() : Passenger(), routeNumber(0) {}
Bus::Bus(string b, int y, double p, int pc, int rn) : Passenger(b, y, p, pc), routeNumber(rn) {}
Bus::Bus(const Bus& other) : Passenger(other), routeNumber(other.routeNumber) {}
Bus::~Bus() { cout << "[Bus] deleted.\n"; }

int Bus::getRouteNumber() const { return routeNumber; }
void Bus::setRouteNumber(int rn) { routeNumber = rn; }

double Bus::calculateTax() const {
    // Берем налог из Passenger и добавляем фиксированный коммерческий сбор за автобус
    return Passenger::calculateTax() + 300.0;
}

void Bus::printTableHeader() const {
    cout << "\n======================================================================================================\n";
    Passenger::printTableHeader(); // Выведет ID, Type, Brand, Year, Passengers
    cout << "| " << setw(10) << "Route #" << "| " << setw(10) << "Price" << "| Tax/Maint\n";
    cout << "------------------------------------------------------------------------------------------------------\n";
}

istream& operator>>(istream& is, Bus& b) {
    is >> static_cast<Passenger&>(b);
    cout << "Enter route number: "; is >> b.routeNumber;
    return is;
}

ostream& operator<<(ostream& os, const Bus& b) {
    os << left << setw(12) << "Bus" << "| ";
    os << static_cast<const Passenger&>(b); // Выведет Brand, Year, Passengers
    os << "| " << setw(10) << b.routeNumber
        << "| $" << setw(9) << b.price << "| $" << b.calculateTax();
    return os;
}
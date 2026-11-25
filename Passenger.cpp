#include "Passenger.h"
Passenger::Passenger() : Transport(), passengerCapacity(0) {}
Passenger::Passenger(string b, int y, double p, int pc) : Transport(b, y, p), passengerCapacity(pc) {}
Passenger::Passenger(const Passenger& other) : Transport(other), passengerCapacity(other.passengerCapacity) {}
Passenger::~Passenger() { cout << "  -> [Passenger] part deleted.\n"; }

int Passenger::getPassengerCapacity() const { return passengerCapacity; }
void Passenger::setPassengerCapacity(int pc) { passengerCapacity = pc; }

double Passenger::calculateTax() const {
    return Transport::calculateTax() + (passengerCapacity * 20.0);
}
void Passenger::printTableHeader() const {
    Transport::printTableHeader();
    cout << "| " << setw(15) << "Passengers";
}

istream& operator>>(istream& is, Passenger& p) {
    is >> static_cast<Transport&>(p);
    cout << "Enter passenger capacity: "; is >> p.passengerCapacity;
    return is;
}

ostream& operator<<(ostream& os, const Passenger& p) {
    os << static_cast<const Transport&>(p);
    os << setw(15) << p.passengerCapacity;
    return os;
}
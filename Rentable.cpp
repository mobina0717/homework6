#include "Rentable.h"

Rentable::Rentable(double dailyPrice) : dailyRentalPrice(dailyPrice), isRented(false) {
    cout << "--> Rentable constructor called" << endl;
}

Rentable::~Rentable() {
    cout << "<-- Rentable destructor called" << endl;
}

#include "Sellable.h"

Sellable::Sellable(double price) : price(price) {
    cout << "--> Sellable constructor called" << endl;
}

Sellable::~Sellable() {
    cout << "<-- Sellable destructor called" << endl;
}

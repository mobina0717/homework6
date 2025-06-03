#include "Vehicle.h"

Vehicle::Vehicle(const string& manufacturer, const string& model, const string& color, int year, int maxSpeed)
    : Item(manufacturer, model, color, year), maxSpeed(maxSpeed) {
    cout << "--> Vehicle constructor called for " << manufacturer << " " << model << endl;
}

Vehicle::~Vehicle() {
    cout << "<-- Vehicle destructor called for " << manufacturer << " " << model << endl;
}

void Vehicle::displayDetails() const {
    Item::displayDetails();
    cout << "  Type: Vehicle" << endl;
    cout << "  Max Speed: " << maxSpeed << " km/h" << endl;
}

#include "Bicycle.h"

Bicycle::Bicycle(const string& manufacturer, const string& model, const string& color, int year, int maxSpeed, double dailyRentalPrice): Item(manufacturer, model, color, year),Vehicle(manufacturer, model, color, year, maxSpeed),Rentable(dailyRentalPrice)
{
     cout << "--> Bicycle constructor called for " << manufacturer << " " << model << endl;
}

Bicycle::~Bicycle() {
    cout << "<-- Bicycle destructor called for " << manufacturer << " " << model << endl;
}

void Bicycle::drive() const {
    cout << "Pedaling the bicycle: ";
    for (int i = 0; i < maxSpeed; ++i) {
        cout << "pedaling ";
    }
    cout << "... Reached max pedaling effort!" << endl;
}

void Bicycle::rent(int days) {
    if (isRented) {
        cout << "Bicycle " << manufacturer << " " << model << " (ID: " << getItemId() << ") is already rented." << endl;
    } else {
        isRented = true;
        double totalCost = dailyRentalPrice * days;
        cout << "Bicycle " << manufacturer << " " << model << " (ID: " << getItemId() << ") rented for " << days << " days." << endl;
        cout << "Total rental cost: $" << totalCost << endl;
    }
}

void Bicycle::returnItem() {
    if (!isRented) {
        cout << "Bicycle " << manufacturer << " " << model << " (ID: " << getItemId() << ") was not rented." << endl;
    } else {
        isRented = false;
        cout << "Bicycle " << manufacturer << " " << model << " (ID: " << getItemId() << ") has been returned." << endl;
    }
}

void Bicycle::displayDetails() const {
    Vehicle::displayDetails();
    cout << "  Role: For Rent" << endl;
    cout << "  Daily Rental Price: $" << dailyRentalPrice << endl;
    cout << "  Status: " << (isRented ? "Rented" : "Available") << endl;
}

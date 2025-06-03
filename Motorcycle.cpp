#include "Motorcycle.h"

Motorcycle::Motorcycle(const string& manufacturer, const string& model, const string& color, int year, int maxSpeed, double price, double dailyRentalPrice):Item(manufacturer, model, color, year), Vehicle(manufacturer, model, color, year, maxSpeed),Sellable(price),Rentable(dailyRentalPrice){
     cout << "--> Motorcycle constructor called for " << manufacturer << " " << model << endl;
}

Motorcycle::~Motorcycle() {
    cout << "<-- Motorcycle destructor called for " << manufacturer << " " << model << endl;
}


void Motorcycle::drive() const {
    cout << "Driving the motorcycle carefully: ";
    int currentSpeed = 0;
    int safeSpeedLimit = maxSpeed / 2;
    while (currentSpeed < safeSpeedLimit) {
        int speedIncrease = rand() % (safeSpeedLimit / 5 + 1) + 1;
        currentSpeed += speedIncrease;
        if (currentSpeed > safeSpeedLimit) currentSpeed = safeSpeedLimit;
        cout << currentSpeed << "... ";
    }
    cout << "Reached safe speed limit (" << safeSpeedLimit << " km/h)!" << endl;
}

void Motorcycle::sell() {
    if (isRented) {
        cout << "Cannot sell Motorcycle " << manufacturer << " " << model << " (ID: " << getItemId() << "). It is currently rented." << endl;
    } else {
        cout << "Processing sale for Motorcycle: " << manufacturer << " " << model << " (ID: " << getItemId() << ")" << endl;
        cout << "Sale Price: $" << price << endl;
        cout << "Sale successful. Item will be removed from the store." << endl;
    }
}

void Motorcycle::rent(int days) {
    if (isRented) {
        cout << "Motorcycle " << manufacturer << " " << model << " (ID: " << getItemId() << ") is already rented." << endl;
    } else {
        isRented = true;
        double totalCost = dailyRentalPrice * days;        cout << "Motorcycle " << manufacturer << " " << model << " (ID: " << getItemId() << ") rented for " << days << " days." << endl;
        cout << "Total rental cost: $" << totalCost << endl;
    }
}

void Motorcycle::returnItem() {
    if (!isRented) {
        cout << "Motorcycle " << manufacturer << " " << model << " (ID: " << getItemId() << ") was not rented." << endl;
    } else {
        isRented = false;
        cout << "Motorcycle " << manufacturer << " " << model << " (ID: " << getItemId() << ") has been returned." << endl;
    }
}

void Motorcycle::displayDetails() const {
    Vehicle::displayDetails();
    cout << "  Role: For Sale & Rent" << endl;
    cout << "  Sale Price: $" << price << endl;
    cout << "  Daily Rental Price: $" << dailyRentalPrice << endl;
    cout << "  Status: " << (isRented ? "Rented" : "Available") << endl;
}

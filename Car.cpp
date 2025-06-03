#include "Car.h"
#include <cstdlib>
#include <ctime> 

Car::Car(const string& manufacturer, const string& model, const string& color, int year, int maxSpeed, double price): Item(manufacturer, model, color, year),Vehicle(manufacturer, model, color, year, maxSpeed),Sellable(price){
    cout << "--> Car constructor called for " << manufacturer << " " << model << endl;
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(0)));
        seeded = true;
    }
}

Car::~Car() {
    cout << "<-- Car destructor called for " << manufacturer << " " << model << endl;
}

void Car::drive() const {
    cout << "Driving the car: ";
    int currentSpeed = 0;
    while (currentSpeed < maxSpeed) {        int speedIncrease = rand() % (maxSpeed / 10 + 1) + 1; // افزایش سرعت تصادفی
        currentSpeed += speedIncrease;
        if (currentSpeed > maxSpeed) currentSpeed = maxSpeed;
        cout << currentSpeed << "... ";
    }
    cout << "Reached max speed (" << maxSpeed << " km/h)!" << endl;
}

void Car::sell() {
    cout << "Processing sale for Car: " << manufacturer << " " << model << " (ID: " << getItemId() << ")" << endl;
    cout << "Sale Price: $" << price << endl;
    cout << "Sale successful. Item will be removed from the store." << endl;
}

void Car::displayDetails() const {
    Vehicle::displayDetails();
    cout << "  Role: For Sale" << endl;
    cout << "  Price: $" << price << endl;
}

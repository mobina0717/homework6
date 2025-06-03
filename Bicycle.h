#ifndef BICYCLE_H
#define BICYCLE_H

#include "Vehicle.h"
#include "Rentable.h"
//nclude "Vehicle.cpp"
//nclude "Rentable.cpp"

class Bicycle : public Vehicle, public Rentable {
public:
    Bicycle(const string& manufacturer, const string& model, const string& color, int year, int maxSpeed, double dailyRentalPrice);

    ~Bicycle() override;

    void drive() const override;

    void rent(int days) override;
    void returnItem() override;

    void displayDetails() const override;
};

#endif

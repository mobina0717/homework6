#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

//nclude "Vehicle.cpp" 
//nclude "Sellable.cpp" 
//nclude "Rentable.cpp" 
#include "Vehicle.h" 
#include "Sellable.h" 
#include "Rentable.h"

class Motorcycle : public Vehicle, public Sellable, public Rentable {
public:
    Motorcycle(const string& manufacturer, const string& model, const string& color, int year, int maxSpeed, double price, double dailyRentalPrice);

    ~Motorcycle() override;

    void drive() const override;

    void sell() override;

    void rent(int days) override;
    void returnItem() override;

    void displayDetails() const override;
};

#endif 

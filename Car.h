#ifndef CAR_H
#define CAR_H

//nclude "Vehicle.cpp" 
//nclude "Sellable.cpp" 
#include "Vehicle.h" 
#include "Sellable.h"

class Car : public Vehicle, public Sellable {
public:
    Car(const string& manufacturer, const string& model, const string& color, int year, int maxSpeed, double price);

    ~Car() override;

    void drive() const override;

    void sell() override;

    void displayDetails() const override;
};

#endif


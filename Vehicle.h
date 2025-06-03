#ifndef VEHICLE_H
#define VEHICLE_H

//#include "Item.cpp" 
#include "Item.h" 

class Vehicle : public Item {
protected:
    int maxSpeed;

public:

    Vehicle(const string& manufacturer, const string& model, const string& color, int year, int maxSpeed);

    ~Vehicle() override;

    virtual void drive() const = 0;

    void displayDetails() const override;

    int getMaxSpeed() const { return maxSpeed; }
};

#endif

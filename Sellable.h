#ifndef SELLABLE_H
#define SELLABLE_H

#include <iostream>

using namespace std;

class Sellable {
protected:
    double price;

public:
    Sellable(double price);

    virtual ~Sellable();

    virtual void sell() = 0;

    double getPrice() const { return price; }
};

#endif 

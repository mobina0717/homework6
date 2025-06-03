#ifndef RENTABLE_H
#define RENTABLE_H

#include <iostream>

using namespace std;

class Rentable {
protected:
    double dailyRentalPrice;
    bool isRented;

public:
    Rentable(double dailyPrice);

    virtual ~Rentable(); 
    virtual void rent(int days) = 0;
    virtual void returnItem() = 0;

    bool getIsRented() const { return isRented; }

    double getDailyRentalPrice() const { return dailyRentalPrice; }
};

#endif

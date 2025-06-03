#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <list> 
#include <limits> 
#include "Item.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Bicycle.h"
#include "Item.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Bicycle.h"
using namespace std;

class Store {
private:
    list<Item*> items;

    list<Item*>::iterator findItemById(int id);

public:
    ~Store();

    void addItem(Item* item);

    void displayAllItems() const;

    void sellItem(int itemId);

    void rentItem(int itemId, int days);

    void returnItem(int itemId);

    void testVehicle(int itemId);

    void run();
};

#endif

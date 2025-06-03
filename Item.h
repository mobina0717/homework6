#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item {
private:
    static int nextId;
    int itemId;

protected:
    string manufacturer;
    string model;
    string color;
    int year;

public:
    Item(const string& manufacturer, const string& model, const string& color, int year);

    virtual ~Item();

    virtual void displayDetails() const;

    int getItemId() const;

    string getManufacturer() const { return manufacturer; }
    string getModel() const { return model; }
    string getColor() const { return color; }
    int getYear() const { return year; }
};

#endif 

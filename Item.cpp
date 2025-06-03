#include "Item.h"

int Item::nextId = 1;

Item::Item(const string& manufacturer, const string& model, const string& color, int year)
    : itemId(nextId++), manufacturer(manufacturer), model(model), color(color), year(year) {
    cout << "--> Item constructor called for " << manufacturer << " " << model << " (ID: " << itemId << ")" << endl;
}

Item::~Item() {
    cout << "<-- Item destructor called for " << manufacturer << " " << model << " (ID: " << itemId << ")" << endl;
}

void Item::displayDetails() const {
    cout << "--- Item Details (ID: " << itemId << ") ---" << endl;
    cout << "  Manufacturer: " << manufacturer << endl;
    cout << "  Model: " << model << endl;
    cout << "  Color: " << color << endl;
    cout << "  Year: " << year << endl;
}

int Item::getItemId() const {
    return itemId;
}

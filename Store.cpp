#include "Store.h"

Store::~Store() {
    cout << "\n--- Store Destructor: Cleaning up items ---" << endl;
    for (Item* item : items) {
        delete item;
    }
    items.clear();
    cout << "--- Item cleanup complete ---" << endl;
}

list<Item*>::iterator Store::findItemById(int id) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getItemId() == id) {
            return it;
        }
    }
    return items.end();
}

void Store::addItem(Item* item) {
    if (item) {
        items.push_back(item);
        cout << "Added item '" << item->getManufacturer() << " " << item->getModel()
             << "' with ID " << item->getItemId() << " to the store." << endl;
    }
}

void Store::displayAllItems() const {
    cout << "\n--- All Items in Store ---" << endl;
    if (items.empty()) {
        cout << "No items currently in the store." << endl;
    } else {
        for (const Item* item : items) {
            item->displayDetails();
            cout << "-------------------------" << endl;
        }
    }
}

void Store::sellItem(int itemId) {
    cout << "\n--- Processing Sale for Item ID " << itemId << " ---" << endl;
    auto it = findItemById(itemId);

    if (it == items.end()) {
        cout << "Error: Item with ID " << itemId << " not found." << endl;
        return;
    }

    Item* item = *it;
    Sellable* sellableItem = dynamic_cast<Sellable*>(item);

    if (sellableItem) {
        sellableItem->sell();
        Car* carItem = dynamic_cast<Car*>(item);
        if (carItem) {
             delete item;
             items.erase(it);
             cout << "Car ID " << itemId << " removed from the store after sale." << endl;
        } else {           
            cout << "Item ID " << itemId << " processed for sale (not a Car, check output for details)." << endl;
            

   } else {
       cout << "Error: Item with ID " << itemId << " is not sellable." << endl;
   }
   cout << "---------------------------------" << endl;
}

void Store::rentItem(int itemId, int days) {
   cout << "\n--- Processing Rental for Item ID " << itemId << " ---" << endl;
   auto it = findItemById(itemId);

   if (it == items.end()) {
       cout << "Error: Item with ID " << itemId << " not found." << endl;
       return;
   }

   Item* item = *it;
   Rentable* rentableItem = dynamic_cast<Rentable*>(item);

   if (rentableItem) {
       rentableItem->rent(days);
   } else {
       cout << "Error: Item with ID " << itemId << " is not rentable." << endl;
   }
    cout << "-----------------------------------" << endl;
}

void Store::returnItem(int itemId) {
   cout << "\n--- Processing Return for Item ID " << itemId << " ---" << endl;
    auto it = findItemById(itemId);

   if (it == items.end()) {
       cout << "Error: Item with ID " << itemId << " not found." << endl;
       return;
   }

   Item* item = *it;
   Rentable* rentableItem = dynamic_cast<Rentable*>(item); 

   if (rentableItem) {
       rentableItem->returnItem();
   } else {
       cout << "Error: Item with ID " << itemId << " is not rentable." << endl;
   }
   cout << "------------------------------------" << endl;
}

void Store::testVehicle(int itemId) {
   cout << "\n--- Testing Vehicle ID " << itemId << " ---" << endl;
    auto it = findItemById(itemId);

   if (it == items.end()) {
       cout << "Error: Item with ID " << itemId << " not found." << endl;
       return;
   }

   Item* item = *it;
   Vehicle* vehicleItem = dynamic_cast<Vehicle*>(item);

   if (vehicleItem) {
       vehicleItem->drive(); 
   } else {
       cout << "Error: Item with ID " << itemId << " is not a vehicle." << endl;
   }
   cout << "---------------------------" << endl;
}

void Store::run() {
    int choice;
    int id, days;

    while (true) {
        cout << "\n--- Store Menu ---" << endl;
        cout << "1. Display All Items" << endl;
        cout << "2. Sell Item" << endl;
        cout << "3. Rent Item" << endl;
        cout << "4. Return Item" << endl;
        cout << "5. Test Vehicle" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        if (cin.fail()) { 
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                displayAllItems();
                break;
            case 2:
                cout << "Enter Item ID to sell: ";
                cin >> id;
                 if (cin.fail()) { cout << "Invalid ID." << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); break; }
                 cin.ignore(numeric_limits<streamsize>::max(), '\n');
                sellItem(id);
                break;
            case 3:
                cout << "Enter Item ID to rent: ";
                cin >> id;
                 if (cin.fail()) { cout << "Invalid ID." << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); break; }
                 cout << "Enter number of days: ";
                 cin >> days;
                  if (cin.fail() || days <= 0) { cout << "Invalid days." << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); break; }
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
                rentItem(id, days);
                break;
            case 4:
                cout << "Enter Item ID to return: ";
                cin >> id;
                 if (cin.fail()) { cout << "Invalid ID." << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); break; }
                 cin.ignore(numeric_limits<streamsize>::max(), '\n');
                returnItem(id);
                break;
            case 5:
                cout << "Enter Item ID to test drive: ";
                cin >> id;
                 if (cin.fail()) { cout << "Invalid ID." << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); break; }
                 cin.ignore(numeric_limits<streamsize>::max(), '\n');
                testVehicle(id);
                break;
            case 6:
                cout << "Exiting store system. Goodbye!" << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

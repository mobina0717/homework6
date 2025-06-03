#include "Store.cpp"
#include "Car.cpp"
#include "Motorcycle.cpp"
#include "Bicycle.cpp"

int main() {
    Store myStore;

    cout << "--- Adding items to the store ---" << endl;

    Car* car1 = new Car("BMW", "M3 GTR", "White and Blue", 2005, 300, 150000.0);
    myStore.addItem(car1);

    Car* car2 = new Car("Porsche", "911 Carrera", "Red", 2020, 310, 200000.0);
    myStore.addItem(car2);

    Motorcycle* moto1 = new Motorcycle("Yamaha", "R1", "Black", 2018, 299, 20000.0, 80.0);
    myStore.addItem(moto1);

    Motorcycle* moto2 = new Motorcycle("Harley-Davidson", "Fat Boy", "Chrome", 2021, 180, 25000.0, 100.0);
    myStore.addItem(moto2);

    // اضافه کردن دوچرخه (فقط اجاره) 
    Bicycle* bike1 = new Bicycle("Trek", "FX 3 Disc", "Silver", 2022, 40, 15.0); // maxSpeed برای دوچرخه تعداد 'pedaling' است
    myStore.addItem(bike1);

    Bicycle* bike2 = new Bicycle("Giant", "Escape 2", "Blue", 2021, 35, 12.0);
    myStore.addItem(bike2);


    cout << "\n--- Initial state of the store ---" << endl;
    myStore.displayAllItems();

    myStore.run();

    cout << "\n--- Program finished ---" << endl;

    return 0;
}

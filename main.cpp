#include <iostream>
#include <vector>
#include <string> 

#include "Developer.h"
#include "JuniorDeveloper.h"
#include "HRPersonnel.h"
#include "Accountant.h"
#include "Manager.h"
#include "SeniorManager.h"

using namespace std;

int main() {
    cout << "--- Creating Employees ---" << endl;

    cout << "\n--- Single Inheritance (Developer) ---" << endl;
    Developer dev(101, "John Doe", 75000.0, "C++", 5);
    dev.displayDetails();
    cout << "Bonus: $" << dev.calculateBonus() << endl;
    cout << endl;

    cout << "--- Multilevel Inheritance (JuniorDeveloper) ---" << endl;
    JuniorDeveloper jrDev(102, "Alice Smith", 50000.0, "Python", 2, 101, 75.5);
    jrDev.displayDetails();
    cout << "Bonus: $" << jrDev.calculateBonus() << endl;
    cout << endl;

    cout << "--- Multiple Inheritance (Manager) ---" << endl;
    Manager mgr(201, "Bob Johnson", 90000.0, 10, "Weekly on Mondays");
    mgr.displayDetails();
    cout << "Bonus: $" << mgr.calculateBonus() << endl;
    mgr.conductMeeting();
    cout << endl;

    cout << "--- Hierarchical Inheritance (HRPersonnel & Accountant) ---" << endl;
    HRPersonnel hr(301, "Carol Williams", 60000.0, "Recruitment", 15);
    hr.displayDetails();
    cout << "Bonus: $" << hr.calculateBonus() << endl;
    cout << endl;

    Accountant acc(401, "David Brown", 65000.0, "CPA", 42);
    acc.displayDetails();
    cout << "Bonus: $" << acc.calculateBonus() << endl;
    cout << endl;

    cout << "--- Hybrid Inheritance (SeniorManager) ---" << endl;
    vector<string> srGoals = {"Increase Revenue by 15%", "Launch New Product"};
    SeniorManager srMgr(202, "Eva Davis", 120000.0, 20, "Daily Stand-up", 500000.0, srGoals);
    srMgr.displayDetails();
    cout << "Bonus: $" << srMgr.calculateBonus() << endl;
    srMgr.conductMeeting();
    cout << endl;

    cout << "--- End of Program (Destructors Called) ---" << endl;

    return 0;
}

#include "Employee.h"

Employee::Employee(int id, const string& n, double s)
    : employeeId(id), name(n), salary(s) {
    cout << "--> Employee constructor called for " << name << endl;
}

Employee::~Employee() {
    cout << "<-- Employee destructor called for " << name << endl;
}

void Employee::displayDetails() const {
    cout << "Employee ID: " << employeeId << endl;
    cout << "Name: " << name << endl;
    cout << "Salary: $" << salary << endl;
}

double Employee::calculateBonus() const {
    return salary * 0.05;
}

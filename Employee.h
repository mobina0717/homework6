#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee {
protected: 
    int employeeId;
    string name;
    double salary;

public:
    Employee(int id, const string& n, double s);

    virtual ~Employee();

    virtual void displayDetails() const;
    virtual double calculateBonus() const;

    int getEmployeeId() const { return employeeId; }
    string getName() const { return name; }
    double getSalary() const { return salary; }
};

#endif

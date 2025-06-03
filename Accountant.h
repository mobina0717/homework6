#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H

#include "Employee.h"

class Accountant : public Employee {
    private:
    string certification;
    int auditedAccounts;

public:
    Accountant(int id, const string& n, double s, const string& cert, int audited);

    ~Accountant() override;

    void displayDetails() const override;
    double calculateBonus() const override;
};

#endif 

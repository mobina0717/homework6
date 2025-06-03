#ifndef HRPERSONNEL_H
#define HRPERSONNEL_H

#include "Employee.h"
class HRPersonnel : public Employee {
private:
    string department;
    int recruitmentCount;

public:
    HRPersonnel(int id, const string& n, double s, const string& dept, int recruitment);

    ~HRPersonnel() override; 
    void displayDetails() const override;
    double calculateBonus() const override;
};

#endif

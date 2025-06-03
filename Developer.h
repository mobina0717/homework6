#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Employee.h"

class Developer : public Employee {
protected:
    string programmingLanguage;
    int yearsOfExperience;

public:
    Developer(int id, const string& n, double s, const string& lang, int exp);

    ~Developer() override;

    void displayDetails() const override;
    double calculateBonus() const override;
};

#endif // DEVELOPER_H

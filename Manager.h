#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h" 
#include "Leadership.h" 
class Manager : public virtual Employee, public virtual Leadership {
public:
    Manager(int id, const string& n, double s, int ts, const string& ms);

    ~Manager() override; 
    void displayDetails() const override;
    double calculateBonus() const override;

    void conductMeeting() const override;
};

#endif

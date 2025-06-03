#include "HRPersonnel.h"

HRPersonnel::HRPersonnel(int id, const string& n, double s, const string& dept, int recruitment)
    : Employee(id, n, s), department(dept), recruitmentCount(recruitment) {
    cout << "--> HRPersonnel constructor called for " << name << endl;
}

HRPersonnel::~HRPersonnel() {
    cout << "<-- HRPersonnel destructor called for " << name << endl;
}

void HRPersonnel::displayDetails() const {
    Employee::displayDetails();
    cout << "Role: HR Personnel" << endl;
    cout << "Department: " << department << endl;
    cout << "Recruitment Count: " << recruitmentCount << endl;
}

double HRPersonnel::calculateBonus() const {
    return Employee::calculateBonus() + (recruitmentCount * 50.0);
}

#include "Accountant.h"

Accountant::Accountant(int id, const string& n, double s, const string& cert, int audited)
    : Employee(id, n, s), certification(cert), auditedAccounts(audited) {
    cout << "--> Accountant constructor called for " << name << endl;
}

Accountant::~Accountant() {
    cout << "<-- Accountant destructor called for " << name << endl;
}

void Accountant::displayDetails() const {
    Employee::displayDetails();
    cout << "Role: Accountant" << endl;
    cout << "Certification: " << certification << endl;
    cout << "Audited Accounts: " << auditedAccounts << endl;
}

double Accountant::calculateBonus() const {
    return Employee::calculateBonus() + (auditedAccounts * 20.0);
}

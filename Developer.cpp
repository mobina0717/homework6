#include "Developer.h"

Developer::Developer(int id, const string& n, double s, const string& lang, int exp)
    : Employee(id, n, s), programmingLanguage(lang), yearsOfExperience(exp) {    cout << "--> Developer constructor called for " << name << endl;
    }
    
    Developer::~Developer() {
        cout << "<-- Developer destructor called for " << name << endl;
    }
    
    void Developer::displayDetails() const {
        Employee::displayDetails();
        cout << "Role: Developer" << endl;
        cout << "Programming Language: " << programmingLanguage << endl;
        cout << "Years of Experience: " << yearsOfExperience << " years" << endl;
    }
    
    double Developer::calculateBonus() const {
        return Employee::calculateBonus() + (yearsOfExperience * 100.0);
    }
    
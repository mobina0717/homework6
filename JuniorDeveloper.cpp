#include "JuniorDeveloper.h"

JuniorDeveloper::JuniorDeveloper(int id, const string& n, double s, const string& lang, int exp, int mentor, double progress)
    : Developer(id, n, s, lang, exp), mentorId(mentor), learningProgress(progress) {
    cout << "--> JuniorDeveloper constructor called for " << name << endl;
}

JuniorDeveloper::~JuniorDeveloper() {
    cout << "<-- JuniorDeveloper destructor called for " << name << endl;
}

void JuniorDeveloper::displayDetails() const {
    Developer::displayDetails(); 
    cout << "Sub-Role: Junior Developer" << endl;
    cout << "Mentor ID: " << mentorId << endl;
    cout << "Learning Progress: " << learningProgress << "%" << endl;
}

double JuniorDeveloper::calculateBonus() const {
    return Developer::calculateBonus() * (learningProgress / 100.0);
}

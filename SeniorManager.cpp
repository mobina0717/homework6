#include "SeniorManager.h"
#include <numeric> 

SeniorManager::SeniorManager(int id, const string& n, double s, int ts, const string& ms,double budget, const vector<string>& goals): Employee(id, n, s),Leadership(ts, ms),budgetResponsibility(budget), strategicGoals(goals)
{
    cout << "--> SeniorManager constructor called for " << getName() << endl;
}

SeniorManager::~SeniorManager() {
    cout << "<-- SeniorManager destructor called for " << getName() << endl;
}

void SeniorManager::displayDetails() const {
    Manager::displayDetails(); 
    cout << "Sub-Role: Senior Manager" << endl;
    cout << "Budget Responsibility: $" << budgetResponsibility << endl;
    cout << "Strategic Goals:" << endl;
    if (strategicGoals.empty()) {
        cout << "  (No specific goals defined)" << endl;
    } else {
        for (const auto& goal : strategicGoals) {
            cout << "  - " << goal << endl;
        }
    }
}

double SeniorManager::calculateBonus() const {
    return Manager::calculateBonus() + (budgetResponsibility * 0.01);
}

void SeniorManager::conductMeeting() const {
    cout << "Senior Manager " << getName() << " is conducting the strategic meeting." << endl;
}

#include "Manager.h"

Manager::Manager(int id, const string& n, double s, int ts, const string& ms)
    : Employee(id, n, s), Leadership(ts, ms)
{
    cout << "--> Manager constructor called for " << getName() << endl;
}

Manager::~Manager() {
    cout << "<-- Manager destructor called for " << getName() << endl;
}

void Manager::displayDetails() const {
    Employee::displayDetails();
    cout << "Role: Manager" << endl;
    cout << "Team Size: " << teamSize << endl;
    cout << "Meeting Schedule: " << meetingSchedule << endl;
}

double Manager::calculateBonus() const {
    return Employee::calculateBonus() + (teamSize * 200.0);
}

void Manager::conductMeeting() const {
    cout << "Manager " << getName() << " is conducting the team meeting." << endl;
}

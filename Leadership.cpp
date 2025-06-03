#include "Leadership.h"

Leadership::Leadership(int ts, const string& ms)
    : teamSize(ts), meetingSchedule(ms) {
    cout << "--> Leadership constructor called with team size " << teamSize << endl;
}

Leadership::~Leadership() {
    cout << "<-- Leadership destructor called" << endl;
}

void Leadership::conductMeeting() const {
    cout << "Conducting a general leadership meeting." << endl;
}

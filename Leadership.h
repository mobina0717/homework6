#ifndef LEADERSHIP_H
#define LEADERSHIP_H

#include <iostream>
#include <string>

using namespace std;

class Leadership {
protected:
    int teamSize;
    string meetingSchedule;

public:
    Leadership(int ts, const string& ms);

    virtual ~Leadership();

    virtual void conductMeeting() const;

    int getTeamSize() const { return teamSize; }
    string getMeetingSchedule() const { return meetingSchedule; }
};

#endif

#ifndef JUNIORDEVELOPER_H
#define JUNIORDEVELOPER_H

#include "Developer.h" 
class JuniorDeveloper : public Developer {
private:
    int mentorId;
    double learningProgress;

public:
    JuniorDeveloper(int id, const string& n, double s, const string& lang, int exp, int mentor, double progress);

    ~JuniorDeveloper() override;
    void displayDetails() const override;
    double calculateBonus() const override;
};

#endif 

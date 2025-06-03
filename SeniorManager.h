#ifndef SENIORMANAGER_H
#define SENIORMANAGER_H

#include "Manager.h" 
#include <vector> 
class SeniorManager : public Manager, public virtual Leadership {
    private:
        double budgetResponsibility;
        vector<string> strategicGoals;
    
    public:
        SeniorManager(int id, const string& n, double s, int ts, const string& ms,
                      double budget, const vector<string>& goals = {}); 
    
        ~SeniorManager() override;
        void displayDetails() const override;
        double calculateBonus() const override;
        void conductMeeting() const override; 
    };
    
    #endif 
    
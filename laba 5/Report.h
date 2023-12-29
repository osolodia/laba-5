#pragma once
#include "User.h"
#include "BMISystem.h"

// Класс "Отчет"
#pragma once
#include "User.h"
#include "BMISystem.h"

// Класс "Отчет"
class Report
{
private:
    User userData[MAX_USERS];
    double bmiData[MAX_USERS];
    int userCount;
public:
    friend class Statistics;
    int getUserCount() const { return userCount; }
    double getBMIData(int i) const { return bmiData[i]; }
    User getUser(int i) const { return userData[i]; }

    void generateReport(BMISystem system) {
        userCount = system.getUserCount();
        for (int i = 0; i < userCount; i++) {
            userData[i] = system.getUser(i);
            bmiData[i] = system.getUser(i).getBMI();
        }
    }
};
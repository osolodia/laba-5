#pragma once
#include "BMISystem.h"
#include "Statistics.h"

// Класс "Интерфейс пользователя"
class BMIService
{
private:
    BMISystem system;
    Statistics statistics;
    Report report;    
public:

    void inputUserInfo() {
        string name;
        int age;
        char gender;
        double height;
        double weight;

        cout << "Enter name: ";
        cin >> name;

        cout << "Enter age: ";
        cin >> age;

        cout << "Enter gender (M/F): ";
        cin >> gender;

        cout << "Enter height (cm): ";
        cin >> height;

        cout << "Enter weight (kg): ";
        cin >> weight;

        User user(name, age, gender, height, weight);
        system.addUser(user);
    }

    void displayReport() {
        report.generateReport(system);
        statistics.updateStatistics(report);

        int userCount = report.getUserCount();

        if (userCount > 0) {
            cout << "========= Report =========" << endl;
            cout << "User Count: " << userCount << endl;

            for (int i = 0; i < userCount; i++) {
                User user = report.getUser(i);
                cout << endl << "User " << i + 1 << ":" << endl;
                user.printData();
            }

            cout << endl << "========= Statistics =========" << endl;
            cout << "Average BMI: " << statistics.getAverageBMI() << endl;
            cout << "Max BMI: " << statistics.getMaxBMI() << endl;
            cout << "Min BMI: " << statistics.getMinBMI() << endl;
        }
        else {
            cout << "No users found." << endl;
        }
    }
};
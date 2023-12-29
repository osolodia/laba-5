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
        try {
            string name;
            int age;
            char gender;
            double height;
            double weight;

            cout << "Enter name: ";
            cin >> name;

            cout << "Enter age: ";
            cin >> age;
            if (age <= 0) {
                throw std::invalid_argument("Invalid age. Please enter a positive value.");
            }

            cout << "Enter gender (M/F): ";
            cin >> gender;
            if (gender != 'M' && gender != 'F') {
                throw std::invalid_argument("Invalid gender. Please enter 'M' or 'F'.");
            }

            cout << "Enter height (cm): ";
            cin >> height;
            if (height <= 0) {
                throw std::invalid_argument("Invalid height. Please enter a positive value.");
            }

            cout << "Enter weight (kg): ";
            cin >> weight;
            if (weight <= 0) {
                throw std::invalid_argument("Invalid weight. Please enter a positive value.");
            }

            User user(name, age, gender, height, weight);
            system.addUser(user);
        }
        catch (const std::exception& e) {
            cout << "Error: " << e.what() << endl;
        }
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
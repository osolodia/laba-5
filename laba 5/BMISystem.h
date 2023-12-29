#pragma once
#include "User.h"

const int MAX_USERS = 100;
// Класс "Система учета ИМТ"
class BMISystem
{
private:
    int userCount;
    User userList[MAX_USERS];
public:
    BMISystem() {
        userCount = 0;
    }
    User getUser(int i) const { return userList[i]; }
    int getUserCount() const { return userCount; }
    void setUserCount(int value) { userCount = value; }

    void addUser(User user) {
        if (userCount < MAX_USERS) {
            userList[userCount] = user;
            userCount++;
        }
    }

    void removeUser(string name) {
        for (int i = 0; i < userCount; i++) {
            if (userList[i].getName() == name) {
                for (int j = i; j < userCount - 1; j++) {
                    userList[j] = userList[j + 1];
                }
                userCount--;
                break;
            }
        }
    }

    double calculateAverageBMI() {
        double totalBMI = 0;
        for (int i = 0; i < userCount; i++) {
            totalBMI += userList[i].getBMI();
        }
        if (userCount > 0) {
            return totalBMI / userCount;
        }
        else {
            return 0;
        }
    }

};


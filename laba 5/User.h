#pragma once
#include <iostream>
#include <string>
using namespace std;

// Класс "Пользователь"
class User {
private:
    string name;
    int age;
    char gender;
    double height;
    double weight;
    double bmi;
public:
    User() {
        name = "0";
        age = 0;
        gender = '0';
        height = 0;
        weight = 0;
        bmi = 0;
    }
    User(string name, int age, char gender, double height, double weight) {
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->height = height;
        this->weight = weight;
        calculateBMI();
    }

    string getName() const { return name; }
    double getBMI() const { return bmi; }

    void calculateBMI() {
        double heightInMeters = height / 100.0;
        bmi = weight / (heightInMeters * heightInMeters);
    }

    void updateUserInfo(string name, int age, char gender, double height, double weight) {
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->height = height;
        this->weight = weight;
        calculateBMI();
    }

    void printData() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "BMI: " << bmi << endl;
    }
};
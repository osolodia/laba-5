#include <iostream>
#include "BMIService.h"
using namespace std;

int main() {
    BMIService bmiService;
  

    while (true) {
        cout << "========= Menu =========" << endl;
        cout << "1. Add User" << endl;
        cout << "2. Display Report" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "========= Add User =========" << endl;
            bmiService.inputUserInfo();
            break;

        case 2:
            cout << "========= Display Report =========" << endl;
            bmiService.displayReport();
            break;

        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        cout << endl;
    }
    return 0;
}
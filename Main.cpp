// Mr-loaded | 10yr C++ & PHP Backend
#include "Bank.h"
#include <iostream>
using namespace std;

int main() {
    Bank bank;
    int choice, userId = -1, accNum;
    string name, password;
    double amount;

    while (true) {
        cout << "\n=== BANK SYSTEM ===" << endl;
        if (userId == -1) {
            cout << "1. Register 2. Login 0. Exit" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Name: "; cin >> name;
                cout << "Password: "; cin >> password;
                userId = bank.registerUser(name, password);
                cout << "Registered! ID: " << userId << endl;
            }
            if (choice == 2) {
                cout << "Name: "; cin >> name;
                cout << "Password: "; cin >> password;
                userId = bank.login(name, password);
                if (userId != -1) cout << "Login success!" << endl;
                else cout << "Wrong credentials!" << endl;
            }
            if (choice == 0) break;
        } else {
            cout << "1. Create Account 2. Deposit 3. Withdraw 4. Balance 5. Logout" << endl;
            cin >> choice;
            if (choice == 1) {
                accNum = bank.createAccount(userId);
                cout << "Account created! Number: " << accNum << endl;
            }
            if (choice == 2) {
                cout << "Account: "; cin >> accNum;
                cout << "Amount: "; cin >> amount;
                bank.deposit(accNum, amount);
            }
            if (choice == 3) {
                cout << "Account: "; cin >> accNum;
                cout << "Amount: "; cin >> amount;
                bank.withdraw(accNum, amount);
            }
            if (choice == 4) {
                cout << "Account: "; cin >> accNum;
                cout << "Balance: " << bank.checkBalance(accNum) << endl;
            }
            if (choice == 5) userId = -1;
        }
    }
    return 0;
}

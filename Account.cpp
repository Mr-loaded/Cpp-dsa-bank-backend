// Mr-loaded | 10yr C++ & PHP Backend
#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(int accNum, int ownerId) {
    accountNumber = accNum; this->ownerId = ownerId; balance = 0;
}
void Account::deposit(double amount) {
    if (amount > 0) { balance += amount; cout << "Deposited: " << amount << endl; }
}
bool Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount; cout << "Withdrawn: " << amount << endl; return true;
    }
    cout << "Not enough money!" << endl; return false;
}
double Account::getBalance() { return balance; }
int Account::getAccountNumber() { return accountNumber; }
int Account::getOwnerId() { return ownerId; }

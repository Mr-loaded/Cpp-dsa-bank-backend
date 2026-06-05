// Mr-loaded | 10yr C++ & PHP Backend
#include "Bank.h"
#include <iostream>
using namespace std;

Bank::Bank() { nextAccountNum = 1001; loadFromFile(); }
Bank::~Bank() { saveToFile(); }

int Bank::registerUser(string name, string password) {
    int id = users.size() + 1;
    users.push_back(User(id, name, password));
    return id;
}
int Bank::login(string name, string password) {
    for (auto &u : users) if (u.getName() == name && u.checkPassword(password)) return u.getId();
    return -1;
}
int Bank::createAccount(int userId) {
    accounts.push_back(Account(nextAccountNum, userId));
    return nextAccountNum++;
}
bool Bank::deposit(int accNum, double amount) {
    for (auto &a : accounts) if (a.getAccountNumber() == accNum) { a.deposit(amount); return true; }
    return false;
}
bool Bank::withdraw(int accNum, double amount) {
    for (auto &a : accounts) if (a.getAccountNumber() == accNum) return a.withdraw(amount);
    return false;
}
double Bank::checkBalance(int accNum) {
    for (auto &a : accounts) if (a.getAccountNumber() == accNum) return a.getBalance();
    return -1;
}
void Bank::saveToFile() {
    ofstream file("data.txt");
    for (auto &u : users) file << "U " << u.getId() << " << u.getName() << endl;
    for (auto &a : accounts) file << "A " << a.getAccountNumber() << " << a.getOwnerId() << " << a.getBalance() << endl;
    file.close();
}
void Bank::loadFromFile() {
    ifstream file("data.txt");
    if (!file) return;
    string type; int id, acc, owner; double bal; string name;
    while (file >> type) {
        if (type == "U") { file >> id >> name; users.push_back(User(id, name, "123")); }
        if (type == "A") { file >> acc >> owner >> bal; accounts.push_back(Account(acc, owner)); }
    }
    file.close();
}

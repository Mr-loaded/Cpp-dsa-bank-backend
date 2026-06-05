// Mr-loaded | 10yr C++ & PHP Backend
#ifndef BANK_H
#define BANK_H
#include "User.h"
#include "Account.h"
#include <vector>
#include <fstream>
using namespace std;

class Bank {
private:
    vector<User> users;
    vector<Account> accounts;
    int nextAccountNum;
    void saveToFile();
    void loadFromFile();
public:
    Bank();
    ~Bank();
    int registerUser(string name, string password);
    int login(string name, string password);
    int createAccount(int userId);
    bool deposit(int accNum, double amount);
    bool withdraw(int accNum, double amount);
    double checkBalance(int accNum);
};
#endif

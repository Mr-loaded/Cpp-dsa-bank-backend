// Mr-loaded | 10yr C++ & PHP Backend
#ifndef ACCOUNT_H
#define ACCOUNT_H
using namespace std;

class Account {
private:
    int accountNumber;
    double balance;
    int ownerId;
public:
    Account(int accNum, int ownerId);
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance();
    int getAccountNumber();
    int getOwnerId();
};
#endif

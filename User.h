// Mr-loaded | 10yr C++ & PHP Backend
#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User {
private:
    int id;
    string name;
    string password;
public:
    User(int id, string name, string password);
    int getId();
    string getName();
    bool checkPassword(string pass);
};
#endif

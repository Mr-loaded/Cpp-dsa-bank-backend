// Mr-loaded | 10yr C++ & PHP Backend
#include "User.h"
User::User(int id, string name, string password) {
    this->id = id; this->name = name; this->password = password;
}
int User::getId() { return id; }
string User::getName() { return name; }
bool User::checkPassword(string pass) { return password == pass; }

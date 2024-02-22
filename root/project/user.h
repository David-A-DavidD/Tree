#ifndef USER_H
#define USER_H

#include <string>

class User {
   public:
    std::string username;  // declare as member variable
    std::string usertype;
    int balance = 0;

    void login();
    void checkPerms(std::string username);
    void setUsername(std::string username);
    void setBalance(int balance);
    void setUsertype(std::string usertype);
    std::string getUsertype();
    std::string getUsername();
    int getBalance();
};

#endif

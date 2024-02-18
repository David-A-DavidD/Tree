#ifndef USER_H
#define USER_H

#include <string>

class User {
   public:
    std::string username;  // declare as member variable

    void login();
    void checkPerms(std::string username);
};

#endif

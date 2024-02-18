#ifndef USER_H
#define USER_H

#include <string>

class User {
   public:
    void login();
    void checkPerms(std::string username);
};

#endif
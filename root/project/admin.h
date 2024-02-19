// admin.h file

#ifndef ADMIN_H
#define ADMIN_H

#include <string>

// Class meant to represent an instance of a Admin user
class Admin {
    // Variables associated with a Admin user
   public:
    std::string transactionCode;
    std::string username;  // Will come from User class
    int balance;           // Will come from User class
};

// Method declarations - see cpp file for more info
void list();
void listActive();
void create(std::string username, std::string accountType);
// void deleteUser(std::string existingUsername); Update this in next phase for proper functionality
void sell(std::string gameName, int price);
void buyGame(std::string gameName, std::string sellerUsername);
void refund(std::string buyerUsername, std::string sellerUsername, int credit);
void addCredit(int credit, int &userAccount);
void logout();

#endif
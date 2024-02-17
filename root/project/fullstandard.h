#ifndef FULL_STANDARD_H
#define FULL_STANDARD_H

#include <string>

// Class meant to represent an instance of a full standard user
class FullStandard {
    // Variables associated with a full standard user
   public:
    std::string transactionCode;
    std::string username;  // Will come from User class
    int balance;           // Will come from User class
};

// Method declarations - see cpp file for more info
void addCredit(int credit, int &userAccount);
std::string buy(std::string gameName, std::string sellerUsername);
void list();
std::string sell(std::string gameName, int price);

#endif
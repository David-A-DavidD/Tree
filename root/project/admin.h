// admin.h file

#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>

#include "user.h"

// Class meant to represent an instance of a Admin user
class Admin : public User {
    // Variables associated with a Admin user
   public:
    std::string transactionCode;
    std::string username;  // Will come from User class
    std::string role;
    int balance;  // Will come from User class

    // Method declarations - see cpp file for more info
    void list();
    void listActive();
    void create(const std::string& username, const std::string& accountType);
    // std::string username, std::string accountType
    //  void deleteUser(std::string existingUsername); Update this in next phase for proper functionality
    bool sell(std::string gameName, double price);
    void buyGame(std::string gameName, std::string sellerUsername);
    void refund(std::string buyerUsername, std::string sellerUsername, int credit);
    void addCredit(int credit, int& userAccount);
    void logout();
    bool isGameAvailable(const std::string& gameName, const std::vector<std::string>& availableGames);
    std::vector<std::string> readAvailableGames(const std::string& filename);
};

#endif
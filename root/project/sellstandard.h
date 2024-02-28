#ifndef SELL_STANDARD_H
#define SELL_STANDARD_H

#include <string>
#include "user.h"

//Class meant to represent an instance of a sell standard user
class SellStandard : public User
{
    //variables associated with a sell standard user
    public:
        std::string transactionCode;
        std::string username; //Will come from User class
        int balance; //Will come from User class

        //Method declarations - see cpp file for more info
        void addCredit(int credit, int &userAccount);
        void sell(std::string gameName, int price);
        void list();
        bool isGameAvailable(const std::string& gameName, const std::vector<std::string>& availableGames);
        std::vector<std::string> readAvailableGames(const std::string& filename);
};

#endif 

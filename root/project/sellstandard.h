#ifndef SELL_STANDARD_H
#define SELL_STANDARD_H

#include <string>

//Class meant to represent an instance of a sell standard user
class SellStandard
{
    //variables associated with a sell standard user
    public:
        std::string transactionCode;
        std::string username; //Will come from User class
        int balance; //Will come from User class

};

//Method declarations - see cpp file for more info
void addCredit(int credit, int &userAccount);
std::string sell(std::string gameName, int price);
void list();

#endif 

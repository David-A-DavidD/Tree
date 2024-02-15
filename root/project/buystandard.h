#ifndef BUY_STANDARD_H
#define BUY_STANDARD_H

#include <string>

//Class meant to represent an instance of a buy standard user
class BuyStandard
{
    //Variables associated with a buy standard user
    public:
        std::string transactionCode;
        std::string username; //Will come from User class
        int balance; //Will come from User class

};

//Method declarations - see cpp file for more info
void addCredit(int credit, int &userAccount);
std::string buy(std::string gameName, std::string sellerUsername);
void list();

#endif 

#ifndef BUY_STANDARD_H
#define BUY_STANDARD_H

#include <string>
#include "user.h"

//Class meant to represent an instance of a buy standard user
class BuyStandard : public User
{
    //Variables associated with a buy standard user
    public:
        std::string transactionCode;
};

//Method declarations - see cpp file for more info
void addCredit(int credit, int &userAccount);
std::string buy(std::string gameName, std::string sellerUsername);
void list();

#endif 

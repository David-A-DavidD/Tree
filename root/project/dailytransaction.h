#ifndef DAILY_TRANSACTION_H
#define DAILY_TRANSACTION_H
#include <string>
//Class for the variables that will be used
class DailyTransaction{
    public:
        std::string username; //Will come from User class
        std::string gameName;//Taken from another class
        std::string userType;//Taken from another file
        int gamePrice;//Taken from another file
        int credit;//taken from another file        

};//end DailyTransaction

//Function to grab the BuyerUserName
std::string recordBuyerUsername();
//Function to grab the SellerUserName
std::string recordSellerUsername();

//create FileRefund
std::string createFileRefund(char transactionCode, std::string buyerUsername, std::string sellerUsername, int credit);

//create FileSell
std::string createFileSell(char transactionCode, std::string gameName, std::string sellerUsername,std::string buyerUserName, int gamePrice);

//create FileSell
std::string createFile(char transactionCode, std::string userName, char userType, int credit);


#endif
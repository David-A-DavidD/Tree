#ifndef DAILY_TRANSACTION_H
#define DAILY_TRANSACTION_H
#include <string>
// Class for the variables that will be used
class DailyTransaction
{
    public:
        std::string username; // Will come from User class
        std::string gameName; // Taken from another class
        std::string userType; // Taken from another file
        int gamePrice;        // Taken from another file
        int credit;           // taken from another file

        // Function to grab the BuyerUserName
        std::string recordBuyerUsername();
        // Function to grab the SellerUserName
        std::string recordSellerUsername();
        void clearEntries();

        void createBuyEntry(std::string transactionCode, std::string gameName, std::string sellerUsername, std::string buyerUsername, double gamePrice);
        void createRefundEntry(std::string transactionCode, std::string buyerUsername, std::string sellerUsername, double credit);
        void createSellEntry(std::string transactionCode, std::string gameName, std::string username, double gamePrice);
        void createEntry(std::string transactionCode, std::string username, std::string userType, double credit);

}; // end DailyTransaction

#endif
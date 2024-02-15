#include <iostream>
#include <ctime>
#include <string>
#include <array>


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
std::string createFileRefund(char transactionCode, std::string gameName, std::string sellerUsername,std::string buyerUserName, int gamePrice);

//create FileSell
std::string createFile(char transactionCode, std::string gameName, std::string sellerUsername, std::string buyerUserName, int gamePrice);
int main(){

    return 0;
}




//Function note complete but will grab the username
std::string recordBuyerUsername(){
    //
    std::string buyerUserName = "placeholder";
    return buyerUserName;
}//end recordBuyerUsername

//Function note complete but will grab the username
std::string recordSellerUsername(){
    //
    std::string sellerUserName = "placeholder";
    return sellerUserName;
}//end recordBuyerUsername

std::string createFileRefund(char transactionCode, std::string buyerUsername, std::string sellerUsername, int credit){
    //Creates the file to return a refund
}

//create FileSell
std::string createFileRefund(char transactionCode, std::string gameName, std::string sellerUsername,std::string buyerUserName, int gamePrice){
    //to be done
}


//create FileSell
std::string createFile(char transactionCode, std::string gameName, std::string sellerUsername, std::string buyerUserName, int gamePrice){
    //to be done
}
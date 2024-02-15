#include <iostream>
#include <ctime>
#include <string>
#include <array>
#include "dailytransaction.h"


int main(){

    //choose 1, 2 or 3 to refund this.
    std::cout << "You may now pick the function that you wish to run" << std::endl;
    std::cout << "Enter 1 for a Refund, Enter 2 for selling a game, Enter 3 for creating a File" << std::endl;
    std::cout << "Or if you wish to exit press any other key."<< std::endl;
    int userpick;
    std::cin >> userpick;

    if (userpick == 1){
        //run the refund
        char code = 'h';
        std::string buyer ="penguin2000";
        std::string seller = "leopard_Seal3000";
        int credit = 9;

        createFileRefund(code, buyer, seller, credit);
    }
    else if(userpick==2){
        //run the refund
        char code = 'h';
        std::string buyer ="penguin2000";
        std::string seller = "leopard_Seal3000";
        std::string gameName = "Antartic Voyage adventure";
        int price =90;
        
        createFileSell(code, gameName,seller,buyer,price);

    }
    else if(userpick==3){
        //Variables for running the file
        char code = 'h';
        std::string userName = "MetroMan";
        char userType ='A';
        int credit =9;

        createFile(code,userName,userType,credit);
    }
    else{
        std::cout<<"You chose to exit out of the program.";
    }
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
    std::cout << "100 dollars refunded" << std::endl;
    return "100 dollars refunded";
}

//create FileSell
std::string createFileSell(char transactionCode, std::string gameName, std::string sellerUsername,std::string buyerUserName, int gamePrice){
    //to be done
    std::cout <<"File sold for 70 dollars" << std::endl;
    return "Game sold for 70 dollars";
}

//create FileSell
std::string createFile(char transactionCode, std::string userName, char userType, int credit){
    //to be done
    std::cout <<"New File Created" << std::endl;
    return "New File Created";

}
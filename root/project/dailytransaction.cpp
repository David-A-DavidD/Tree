#include <iostream>
#include <ctime>
#include <string>
#include <array>
#include "dailytransaction.h"
#include <fstream> 
#include <iostream>


int main(){

    createEntry("01", "test_user", "FS", 145);
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

// Create an entry for Daily Transaction File for create, delete, add_credit, logout
// format:  XX_UUUUUUUUUUUUUUU_TT_CCCCCCCCC
    // where:	
    // XX is a two-digit transaction code: 01-create, 02-delete, 06-add credit, 00-end of session 
    // UUUUUUUUUUUUUUU is the username (buyer if two users in the transaction)
    // TT is the user type (AA=admin, FS=full-standard, BS=buy-standard, SS=sell-standard)
    // CCCCCCCCC is the available credit
    // _ is a space
void createEntry(std::string transactionCode, std::string username, std::string userType, double credit){
    
    std::string nameSect = "UUUUUUUUUUUUUUU";
    std::string creditSect = "CCCCCCCCC";

    // Replace spaces in username with underscores 
    std::replace(username.begin(), username.end(), ' ', '_');

    //fill in nameSect according to username length
    int len = nameSect.length();
    if(username.length() > len){
        username = username.substr(0, len);
    }
    else if(username.length() < len){
        int leftover = len - username.length();
        username.append(leftover, '_');
    }

    // fill in creditSect according to credit length
    len = creditSect.length();
    std::string creditString = std::to_string(credit);

    // "." found in credit amount
    if (creditString.find('.') == std::string::npos){
        creditString.append(".00");
    }

    if(creditString.length() > len){
        creditString = creditString.substr(0, len);
    }
    else if (creditString.length() < len){
            int leftover = len - creditString.length();
            creditString.append(leftover, '0');
    }
    
    // Entry that will be added to end of Daily Transactions File
    std::string entry = (transactionCode + "_" + username + "_" + userType + "_" + creditString);

    // Open the file in append mode
    std::ofstream outputFile("dailytransactions.txt", std::ios::app);

    // Check if the file was opened successfully
    if (outputFile.is_open()) {
        // Append content to the file
        outputFile << entry << "\n";

        // Close the file
        outputFile.close();
    } else {
        std::cerr << "Failed to open dailytransactions.txt for writing.\n";
    }

}
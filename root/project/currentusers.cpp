#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include "currentusers.h"

// Method to create a user entry into the Current Users File
// format:  UUUUUUUUUUUUUUU_TT_CCCCCCCCC
    // where:	
    // UUUUUUUUUUUUUUU is the username 
    // TT is the user type (AA=admin, FS=full-standard, BS=buy-standard, SS=sell-standard)
    // CCCCCCCCC is the available credit
    // _ is a space
void CurrentUsers::createEntry(std::string username, std::string userType, double credit){

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
    
    // Entry that will be added to end of Current Users File
    std::string entry = (username + "_" + userType + "_" + creditString);

    // Open the file in append mode
    std::ofstream outputFile("currentusers.txt", std::ios::app);

    // Check if the file was opened successfully
    if (outputFile.is_open()) {
        // Append content to the file
        outputFile << entry << "\n";

        // Close the file
        outputFile.close();
    } else {
        std::cerr << "Failed to open currentusers.txt for writing.\n";
    }

}

//Create an “END” user placed at the end of the file
void CurrentUsers::createEndUser(){
    //TODO: still need to implement this functionality
    
    std::string entry = "END________________000000000";

    std::string fileName = "currentusers.txt";

}

int main(){

    CurrentUsers cuFile;
    cuFile.createEntry("mc   555", "AA", 1234.57);

    return 0;
}
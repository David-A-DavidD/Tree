#include <iostream>
#include <ctime>
#include <string>
#include "availablegames.h"

// Method to create a game entry into the Available Games File:
// format:  IIIIIIIIIIIIIIIIIIIIIIIIII_SSSSSSSSSSSSSSS_PPPPPP
    // where:	
    // IIIIIIIIIIIIIIIIIIIIIIIIII is the game name 
    // SSSSSSSSSSSSSSS is the seller’s username
    // PPPPPP is the price of the game
    // _ is a space
File createEntry(std::string gameName, std::string sellerUsername, int gamePrice){

    // TODO: handle specific test cases of user input
    // TODO: spaces inbetween names turn into "_"

    std::string gameSect = "IIIIIIIIIIIIIIIIIIIIIIIIII";
    std::string sellerSect = "SSSSSSSSSSSSSSS";
    std::string priceSect = "PPPPPP";

    //fill in gameSect according to gameName length
    int len = gameSect.length();
    if(gameName.length() > len){
        gameName = gameName.substr(0, len);
    }
    else if(gameName.length() == len){
        gameName = gameName;
    }
    else if(gameName.length() < len){
        int leftover = len - gameName.length();
        gameName.append(leftover, '_');
    }

    //fill in sellerSect according to sellerUsername length
    len = sellerSect.length();
    if(sellerUsername.length() > len){
        sellerUsername = sellerUsername.substr(0, len);
    }
    else if(sellerUsername.length() == len){
        sellerUsername = sellerUsername;
    }
    else if(sellerUsername.length() < len){
        int leftover = len - sellerUsername.length();
        sellerUsername.append(leftover, '_');
    }

    //fill in priceSect according to gamePrice length
    // TODO: handle when user enters cents 

    len = priceSect.length();
    std::string gamePriceString = std::to_string(gamePrice);

    // account for ".00 after price"
    if(gamePriceString.length() + 3 == len){
        gamePriceString.append(".00");
    }
    else if (gamePriceString.length() + 3 < len){
        int leftover = (len - gamePriceString.length()) - 1;
        gamePriceString += '.';
        gamePriceString.append(leftover, '0');
    }

    // Entry that will be added to end of Available Games File
    std::string entry = (gameName + "_" + sellerUsername + "_" + gamePriceString);

    // TODO: Append "entry" to Available Games File and return file

    std::cout << entry << "\n";

    File file;
    return file;
}

//Method to create an “END” game that is placed at the end of the file
void createEndUser(){
    
    std::string entry = "END______________________________________________";

    // TODO: place END entry at the end of Available Games File

}

int main(){

    //TODO: main body
    createEntry("modern warfare", "michael", 80);

    return 0;
}
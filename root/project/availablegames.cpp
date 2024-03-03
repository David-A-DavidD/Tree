#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include "availablegames.h"

// Method to create a game entry into the Available Games File:
// format:  IIIIIIIIIIIIIIIIIIIIIIIIII_SSSSSSSSSSSSSSS_PPPPPP
    // where:	
    // IIIIIIIIIIIIIIIIIIIIIIIIII is the game name 
    // SSSSSSSSSSSSSSS is the seller’s username
    // PPPPPP is the price of the game
    // _ is a space
void AvailableGames::createEntry(std::string gameName, std::string sellerUsername, double gamePrice){

    std::string gameSect = "IIIIIIIIIIIIIIIIIIIIIIIIII";
    std::string sellerSect = "SSSSSSSSSSSSSSS";
    std::string priceSect = "PPPPPP";

    // Replace spaces in gameName and sellerUsername with underscores 
    std::replace(gameName.begin(), gameName.end(), ' ', '_');
    std::replace(sellerUsername.begin(), sellerUsername.end(), ' ', '_');

    //fill in gameSect according to gameName length
    int len = gameSect.length();
    if(gameName.length() > len){
        gameName = gameName.substr(0, len);
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
    else if(sellerUsername.length() < len){
        int leftover = len - sellerUsername.length();
        sellerUsername.append(leftover, '_');
    }

    //fill in priceSect according to gamePrice length

    len = priceSect.length();
    std::string gamePriceString = std::to_string(gamePrice);

    // "." found in credit amount
    if (gamePriceString.find('.') == std::string::npos){
        gamePriceString.append(".00");
    }

    if(gamePriceString.length() > len){
        gamePriceString = gamePriceString.substr(0, len);
    }
    else if (gamePriceString.length() < len){
            int leftover = len - gamePriceString.length();
            gamePriceString.append(leftover, '0');
    }

    // Entry that will be added to end of Available Games File
    std::string entry = (gameName + "_" + sellerUsername + "_" + gamePriceString);

    // Open the file in append mode
    std::ofstream outputFile("availablegames.txt", std::ios::app);

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

//Create an “END” game placed at the end of the file
void AvailableGames::createEndUser(){

    //TODO: still need to implement this functionality
    
    std::string entry = "END________________________________________000000";

}

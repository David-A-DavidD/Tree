#include "fullstandard.h"

#include <ctime>
#include <iostream>
#include <string>

/*
    This class and file represents an instance of a user with Full-Standard privileges.
    Any/all methods that a Full-Standard user can use are represented here including...
    - viewing a list of available games
    - logging the user out of the system
    - letting the user put a game up for sale
    - buying a game
    - adding credit to their account

   <<< EDIT THIS COMMENTS >>>
    Currently, the class takes in a username and balance parameter. This will eventually be taken
    from the User class, which this class will be inheriting the username attribute from.

    Eventually, this class will be able to send File information to the Files class and
    its related children to save, write, or read any external files.
*/

// This method is used to give a predetermined credit amount and add it to the logged in user's account
void addCredit(int credit, int &userAccount) {
    userAccount += credit;
}

// This method is used to put a game from an associated seller in the current user accounts file
std::string buy(std::string gameName, std::string sellerUsername) {
    // TODO: - Deduct game price from buyer balance
    //       - Credit seller with game price
    //       - Add game to user's game collection file
    //       - Save transaction to daily transaction file

    return "04 gameName sellerUsername username gamePrice";  // Return code for buy transaction
}

// This method is used to list all games available in the available games file
void list() {
    // TODO: Iterate through available games file and display all relevant details
}

// this Method is used to put a game up for sale by the user
std::string sell(std::string gameName, int price) {
    // TODO: - implement logic to let user put a game for sale
    //       - Credit seller with game price
    //       - Remove game from user's game collection file once used
    //       - Save transaction to daily transaction file
    return "05 gameName price username gamePrice";  // Return code for sell transaction
}

int main() {
    // Variables
    FullStandard user;
    int creditInput;
    std::string gameInput;
    std::string sellerInput;
    int sellPrice;  // variable for selling price of game

    user.balance = 0;           // placeholder
    user.username = "Fareeha";  // placeholder

    while (true)  // infinite loop to keep user in the session
    {
        std::cout << "Welcome " + user.username + ". Please Enter a Transaction Command: ";
        std::cin >> user.transactionCode;

        if (user.transactionCode == "list") {
            // TODO: If user calls list command, iterate through AvailableGames file and display all contents in that file

            // list();
        } else if (user.transactionCode == "buy") {
            std::cout << "What game would you like to purchase? ";
            std::cin.ignore();                  // Clear the input buffer
            std::getline(std::cin, gameInput);  // get input

            // TODO: Check if game is in available games file & if user has enough credit to purchase game. If not, throw error
            // TODO: Check if game is already in user library. If so, throw error

            std::cout << "What is the seller username? ";
            std::cin >> sellerInput;  // get input
            std::cin.ignore();        // Clear the input buffer

            // TODO: Check if seller is in current user accounts file. If not, throw error
            // buy(gameInput, sellerInput);
            std::cout << "Success! " << gameInput << " has been added to your account." << std::endl;

        } else if (user.transactionCode == "sell") {
            // prompt user for game name and the selling price
            std::cout << "Enter the name of the game you would like to sell: ";
            std::cin.ignore();                  // Clear the input buffer
            std::getline(std::cin, gameInput);  // get input

            // TODO: Check if game is in available games file & if user can sell. If not, throw error
            // TODO: Check if game is already sold. If so, throw error

            std::cout << "Enter the selling price of the game: ";
            std::cin >> sellPrice;  // get selling price input
            std::cin.ignore();      // Clear the input buffer

            // TODO: Check if seller is in current user accounts file. If not, throw error
            // sell(gameInput, price);

            std::cout << "Success! " << gameInput << " has been added to your selling list." << std::endl;

        } else if (user.transactionCode == "addcredit") {
            std::cout << "How much credit would you like to add? ";
            std::cin >> creditInput;  // get input

            if (creditInput < 0 || creditInput > 1000) {
                std::cout << "Error - Invalid Credit Amount" << std::endl;
            } else {
                addCredit(creditInput, user.balance);  // perform credit addtion
                std::cout << "Success! Your account now has " << user.balance << " credit." << std::endl;
            }
        } else if (user.transactionCode == "logout") {
            std::cout << "Logging out of " << user.username << "'s account...";

            // TODO: Write daily transaction file upon logout

            break;  // breaks out of loop to end session
        } else {
            // Output for errors in transaction command input
            std::cout << "Error - Unrecognized Command" << std::endl;
            std::cout << "Note: transaction codes MUST be all lowercase (ex: login, buy, etc.), please try again." << std::endl;
        }
    }
    return 0;
}
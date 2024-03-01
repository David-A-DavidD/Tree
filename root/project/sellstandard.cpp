#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <algorithm>
#include "sellstandard.h"
#include "user.h"
#include <sstream>

/*
    This class and file represents an instance of a user with Sell-Standard privileges.
    Any/all methods that a Sell-Standard user can use are represented here including...
    - selling a game
    - viewing a list of available games
    - adding credit to their account

    Currently, the class takes in a username and balance parameter. These will eventually be taken
    from the User class, which this class will be inheriting the username attribute from.

    Eventually, this class will be able to send File information to the Files class and
    its related children to save, write, or read any external files.
*/

//This method is used to give a predetermined credit amount and add it to the logged in user's account
void SellStandard::addCredit(int credit, int &userAccount)
{
    userAccount += credit;
}

bool SellStandard::isGameAvailable(const std::string& gameName, const std::vector<std::string>& availableGames) {
    for (const std::string& entry : availableGames) {
        // Read only the first 25 characters of the entry
        std::string gameEntry = entry.substr(0, 25);

        // Remove trailing underscores
        size_t lastChar = gameEntry.find_last_not_of('_');
        if (lastChar != std::string::npos) {
            gameEntry = gameEntry.substr(0, lastChar + 1);
        }

        // If the game name matches, return true (game is available)
        if (gameEntry == gameName) {
            return true;
        }
    }
    // Game not found in available games list
    return false;
}


void SellStandard::sell(std::string gameName, int price) {
    // Load available games from file
    std::ifstream file("availablegames.txt");
    std::vector<std::string> availableGames;
    std::string line;
    while (std::getline(file, line)) {
        availableGames.push_back(line);
    }
    file.close();

    // Check if the game is available for sale
    if (isGameAvailable(gameName, availableGames)) {
        std::cout << gameName << " has been put up for sale for $" << price << "." << std::endl;
        // TODO: Add code here to update the available games file with the new game for sale
    } else {
        std::cout << "Error - Game '" << gameName << "' is not available for sale." << std::endl;
    }
}


//This method is used to list all games available in the available games file
void SellStandard::list()
{
    //TODO: Iterate through available games file and display all relevant details
    // Open the file
    std::ifstream file("availablegames.txt"); 
    
    // Check if file is open successfully
    if (!file.is_open()) {
        std::cerr << "Error opening file: availablegames.txt" << std::endl;
        return;
    }
    
    std::cout << "Game Name\t\t   Owner\t   Price" <<std::endl;
    std::cout << "-------------------------------------------------" << std::endl;

    // Read and display each line
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    
    // Close the file
    file.close();
}

/*
int main()
{
    //Variables
    SellStandard user; 
    int creditInput;
    std::string gameInput;
    std::string sellerInput;
    int sellingPrice;

    user.balance = 0; //placeholder
    user.username = "Justin"; //placeholder

    while (true) //infinite loop to keep user in the session
    {
        std::cout << "Welcome " + user.username + ". Please Enter a Transaction Command: ";
        std::cin >> user.transactionCode;

        if (user.transactionCode == "list")
        {
            //TODO: If user calls list command, iterate through AvailableGames file and display all contents in that file

            //list();
        }else if (user.transactionCode == "sell")
        {
            std::cout << "What game would you like to sell? ";
            std::cin.ignore(); // Clear the input buffer
            std::getline(std::cin, gameInput); //get input
        
            //TODO: Check if gameInput is <= 25 characters and is unique. If not, throw error

            std::cout << "How much would you like to sell it for? ";
            std::cin >> sellingPrice; //get input
            std::cin.ignore(); // Clear the input buffer

            if (sellingPrice > 999.99)
            {
                std::cout << "Error - Invalid Selling Price" << std::endl;
            }

            //sell(gameInput, sellingPrice);
            std::cout << gameInput << " has been put up for sale for $" << sellingPrice << "." << std::endl;

        }else if (user.transactionCode == "addcredit")
        {
            std::cout << "How much credit would you like to add? ";
            std::cin >> creditInput; //get input
            
            //Ensuring credit to be added is valid
            if (creditInput < 0 || creditInput > 1000)
            {
                std::cout << "Error - Invalid Credit Amount" << std::endl;
            }else
            {
                addCredit(creditInput, user.balance);
                std::cout << "Success! Your account now has " << user.balance << " credit." << std::endl;
            }
        }else if (user.transactionCode == "logout")
        {
            std::cout << "Logging out of " << user.username << "'s account...";

            //TODO: Write daily transaction file upon logout

            break; //breaks out of loop to end session
        }else
        {
            //Output for errors in transaction command inputs
            std::cout << "Error - Unrecognized Command" << std::endl;
            std::cout << "Note: transaction codes MUST be all lowercase (ex: login, buy, etc.), please try again." << std::endl;
        }
    }
    return 0;
}
*/
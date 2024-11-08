// including relevant libraries and classes
#include "admin.h"

#include <algorithm>  //to find if user exists
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "user.h"

/* This admin file may not be fully functional as certain functions and function calls are commented out due to functionality issues.
// This files functionality is mostly commented out and may not be an executable.
    This class and file represents an instance of a user with Admin privileges.
    Any/all methods that a Admin user can use are represented here including...
    - buying a game
    - selling a game
    - viewing a list of available games
    - viewing active list
    - adding credit to their account
    - creating and deleting user
    - refunign user
    - loggin out



    Currently, the class takes in a username and balance parameter. This will eventually be taken
    from the User class, which this class will be inheriting the username attribute from.

    Eventually, this class will be able to send File information to the Files class and
    its related children to save, write, or read any external files.
*/

// Method to display all games in the available games file
void Admin::list() {
    // Open the file
    std::ifstream file("availablegames.txt");

    // Check if file is open successfully
    if (!file.is_open()) {
        std::cerr << "Error opening file: availablegames.txt" << std::endl;
        return;
    }

    std::cout << "Game Name\t\t   Owner\t   Price" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    // Read and display each line
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    // Close the file
    file.close();
}

// Method to display all active users on the system, along with their relevant information
void Admin::listActive() {
    // Open the file
    std::ifstream file("currentusers.txt");

    // Check if file is open successfully
    if (!file.is_open()) {
        std::cerr << "Error opening file: currentusers.txt" << std::endl;
        return;
    }

    std::cout << "User Name\tUser Type\tCredit" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    // Read and display each line
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    // Close the file
    file.close();
}

// Method to allow the admin to create another user on the system

void Admin::create(const std::string& username, const std::string& accountType) {  // MOVED variable declarations outside of function definition
                                                                                   // causing errors  User newUser(username, accountType);
    // TODO: implement logic to create a new user and accountType

    // // asking for user type
    // std::cout << "Enter the user type (Admin, FS, BS, SS): " << std::endl;
    // std::cin >> accountType;

    // std::cout << "Creating a new user with username: " << username << "and account type: " << accountType << std::endl;
    // // TODO: implement logic to record this in daily transaction file
}

// Method to allow the admin to delete an existing user on the system
void deleteUser() {  // MOVED variable declarations outside of function definition
    std::string existingUsername;
    std::cout << "Enter the  username: " << std::endl;
    std::cin >> existingUsername;
    std::cout << "Deleting user with username: " << existingUsername << std::endl;
    // TODO: implement logic to delete an existing user
    // TODO: implement logic to record this in daily transaction file
}

bool Admin::isGameAvailable(const std::string& gameName, const std::vector<std::string>& availableGames) {
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

bool Admin::sell(std::string gameName, double price) {
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
        std::cout << "Error - " << gameName << " is already on sale." << std::endl;
        return false;
    } else {
        std::cout << gameName << " has been put up for sale for $" << price << "." << std::endl;
        return true;
    }
}

/*
// Method to allow the user to purchase a game from the available games library
void Admin::buyGame(std::string gameName, std::string sellerUsername) {
    std::cout << "Enter the  game name: " << std::endl;
    std::cin >> gameName;
    std::cout << "Enter the seller username: " << std::endl;
    std::cin >> sellerUsername;
    std::cout << "Buying a game: " << gameName << "seller username: " << sellerUsername << std::endl;
    // TODO: implement logic to buy game
    // Add the new game to the user’s collection
    // TODO: implement logic to credit the seller with an amount equal to the game’s price and deduct that amount from the buyer
    // TODO: implement logic to should save this information to the daily transaction file

    // load available games file to read
    std::ifstream file("availablegames.txt");
    std::vector<std::string> availableGames;
    std::string line;
    while (std::getline(file, line)) {
        availableGames.push_back(line);
    }
    file.close();

    // check if game available for purchase
    auto check = std::find_if(availableGames.begin(), availableGames.end(), [&gameName, &sellerUsername](const std::string& game) {
        // ensure these indexes account for what is stored in txt files
        std::string entryGameName = game.substr(0, 25);
        std::string entrySellerUsername = game.substr(25, 15);
        return entryGameName == gameName && entrySellerUsername == sellerUsername;
    });

    // if no such game , throw error
    if (check == availableGames.end()) {
        std::cout << "Error, game not avaialblae or incorrectly read from file" << std::endl;
        return;
    }
    // get game price from availablegames.txt file
    double gamePrice = std::stod(check->substr(40));  // figure out if i can remove this

    // add the new game to the user’s collection
    // test
    std::ofstream updateAvailableGamesFile("availablegames.txt");
    for (const std::string& gameName : availableGames) {
        updateAvailableGamesFile << gameName << "\n";
    }
    updateAvailableGamesFile.close();

    // credit the seller with an amount equal to the game’s price and deduct that amount from the buyer )
    // may have issue w/working
    double sellerCredit;
    sellerCredit += gamePrice;

    // save this information to the daily transaction file
    std::ofstream dailyTransactionFile("dailytransactions.txt", std::ios::app);
    dailyTransactionFile << "Buy\t" << sellerUsername << "\t" << gameName << "\t" << gamePrice << "\n";
    dailyTransactionFile.close();

    std::cout << "Success! " << gameName << " has been added to your collection." << std::endl;
}
*/

// function to check if a username exists in the user accounts / in the txt files (try reading dynamically if this doesnt work)
bool isUserExist(const std::string& username, const std::vector<std::string>& userAccount) {
    return std::find(userAccount.begin(), userAccount.end(), username) != userAccount.end();
}

// Method to allow the admin to refund a game from a buyer and credit the seller accordingly
void Admin::refund(std::string buyerUsername, std::string sellerUsername, int credit) {
    std::string line;
    std::vector<int> balances;
    std::cout << "Enter the buyer username: " << std::endl;
    std::cin >> buyerUsername;
    std::cout << "Enter the seller  username: " << std::endl;
    std::cin >> sellerUsername;
    std::cout << "Enter the amount of credit to transfer: " << std::endl;
    std::cin >> credit;

    std::cout << "Refunding game from buyer " << buyerUsername << "to seller: " << sellerUsername << "Amount of credit to transfer: " << credit << std::endl;
    // TODO: implement logic to refund game MIGHT HAE TO CHANGE LOGIC
    // load balances from available games.txt
    std::ifstream availablegamesFile("availablegames.txt");

    while (std::getline(availablegamesFile, line)) {
        balances.push_back(std::stoi(line));
    }
    availablegamesFile.close();

    // refunding causing errors
    // userAccount += credit;
    // userAccount += credit;

    // TODO: implement logic to transfer the specified amount of credit from the seller’s credit balance to the buyer’s credit balance.

    // check if buyer and seller username exists
    std::ifstream userAccountsFile("currentusers.txt");
    std::vector<std::string> userAccount;

    while (std::getline(userAccountsFile, line)) {
        userAccount.push_back(line);  // each line of user account info stored as seperate string in vector (remove if needed)
    }
    userAccountsFile.close();

    if (!isUserExist(buyerUsername, userAccount) || !isUserExist(sellerUsername, userAccount)) {
        std::cerr << "Error - either the Buyer or Seller username does not exist" << std::endl;
        return;
    }
    // TODO: implement logic should save this information for the daily transaction file
    std::ofstream dailyTransactionFile("dailytransactions.txt, std::ios::app");
    dailyTransactionFile << "Refund\t" << buyerUsername << "\t" << sellerUsername << "\t" << credit << std::endl;
    dailyTransactionFile.close();

    std::cout << "Refunding the game" << buyerUsername << "to seller" << sellerUsername << "amount of credit transferred" << credit << std::endl;
}

// Method that lets the user add a specified amount of credit to the specified account username
void Admin::addCredit(int credit, int& userAccount) {
    if (role == "AA") {
        std::cout << "Enter the amount of credit to transfer: " << std::endl;
        std::cin >> credit;
        std::cout << "Enter the username where credit is being added: " << std::endl;
        std::cin >> userAccount;
        std::cout << "Adding credit: " << credit << "to user account: " << userAccount << std::endl;
    } else {
        userAccount += credit;
    }
    // TODO: implement logic to let user add specified amount of credit to the specified account username
    // TODO: set logic so A maximum of $1000.00 can be added to an account in a given session.
    //- if else statement
    // TODO: implement logic should save this information for the daily transaction file
}

// Method to log the user out of the system
void logout() {
    // TODO: implement logic to log user out of the system
    std::cout << "Loggin user out of the system..." << std::endl;
}

/*
int main() {
    // Variables
    Admin admin;
    int creditInput;
    std::string gameInput;
    std::string sellerInput;

    admin.balance = 0;          // placeholder
    admin.username = "Justin";  // placeholder

    while (true)  // infinite loop to keep user in the session
    {
        std::cout << "Welcome " + admin.username + ". Please Enter a Transaction Command: ";
        std::cin >> admin.transactionCode;

        if (admin.transactionCode == "list") {
            // TODO: If user calls list command, iterate through AvailableGames file and display all contents in that file

            // list();

        } else if (admin.transactionCode == "list Active") {
            std::cout << "Listing all active users on the system" << std::endl;
            // TODO: implement logic to display the list of active accounts and their relevant information onto the terminal
            // need to pull this information from user account data (reading the txt files)

        } else if (admin.transactionCode == "create") {
            // TODO: make transaction code functional and function call working
            //  admin.create();

            // TODO: make this else if statement for delete transaction workable
            //  } else if (admin.transactionCode == "delete") {
            //  TODO: make transaction code functional and function call working
            //   admin.deleteUser();
        } else if (admin.transactionCode == "sell") {
            // TODO: make transaction code functional and function call working
            //  admin.sell();
        } else if (admin.transactionCode == "buy") {
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
        } else if (admin.transactionCode == "addcredit") {
            std::cout << "How much credit would you like to add? ";
            std::cin >> creditInput;  // get input

            if (creditInput < 0 || creditInput > 1000) {
                std::cout << "Error - Invalid Credit Amount" << std::endl;
            } else {
                addCredit(creditInput, admin.balance);  // perform credit addtion
                std::cout << "Success! Your account now has " << admin.balance << " credit." << std::endl;
            }
        } else if (admin.transactionCode == "logout") {
            std::cout << "Logging out of " << admin.username << "'s account...";

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
*/

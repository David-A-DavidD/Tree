#include <fstream>
#include <iostream>

#include "admin.h"
#include "availablegames.h"
#include "buystandard.h"
#include "currentusers.h"
#include "dailytransaction.h"
#include "sellstandard.h"
#include "user.h"

// Compile command: g++ main.cpp user.cpp currentusers.cpp availablegames.cpp dailytransaction.cpp  admin.cpp -o main && ./main

int main() {
    User user;
    Admin currentUser;
    Admin admin;  // usage correct?

    std::string username;
    std::string command;

    DailyTransaction dtf;
    AvailableGames availableGamesFile;

    bool isLoggedIn = false;

    currentUser.role = "00";

    while (command != "login") {
        std::cout << "Welcome. Please log in using the login command: ";
        std::cin >> command;

        if (command == "login") {
            // Calling login function
            dtf.clearEntries();
            user.login();
            isLoggedIn = true;
        } else {
            std::cout << "Error - please type login to log into your account." << std::endl;
        }

        if (command == "exit") {
            std::cout << "Exiting the system..." << std::endl;
            break;
        }
    }

    // Implement a way to set current user to object of corresponding class (ex: Admin currentUser if user is AA in current accounts file)

    if (user.getUsertype() == "AA") {
        currentUser.role = "AA";

    } else if (user.getUsertype() == "FS") {
        currentUser.role = "FS";

    } else if (user.getUsertype() == "BS") {
        currentUser.role = "BS";

    } else if (user.getUsertype() == "SS") {
        currentUser.role = "SS";
    }

    // Set BuyStandard user attributes inherited from User
    currentUser.transactionCode = "";
    currentUser.username = user.getUsername();
    currentUser.balance = user.getBalance();

    // Possible TODO: perform checkPerms in each command condition to see if user can access it. If they aren't allowed, print error message?
    while (isLoggedIn == true)  // infinite loop to keep user in the session
    {
        std::cout << "Welcome " << currentUser.username << " (" << currentUser.role << "). Please Enter a Transaction Command: ";
        std::cin >> currentUser.transactionCode;

        if (currentUser.transactionCode == "list" && (currentUser.role == "AA" || currentUser.role == "FS" || currentUser.role == "SS" || currentUser.role == "BS")) {
            // TODO: If user calls list command, iterate through AvailableGames file and display all contents in that file
            currentUser.list();
        } else if (currentUser.transactionCode == "listactive" && currentUser.role == "AA") {
            currentUser.listActive();
        } else if (currentUser.transactionCode == "buy" && (currentUser.role == "AA" || currentUser.role == "BS" || currentUser.role == "FS")) {
            std::string gameInput;
            std::string sellerInput;

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
        } else if (currentUser.transactionCode == "addcredit" && (currentUser.role == "AA" || currentUser.role == "FS" || currentUser.role == "SS" || currentUser.role == "BS")) {
            int creditInput;

            if (currentUser.role != "AA") {
                std::cout << "How much credit would you like to add? ";
                std::cin >> creditInput;  // get input
            }

            if (creditInput < 0 || creditInput > 1000) {
                std::cout << "Error - Invalid Credit Amount" << std::endl;
            } else {
                currentUser.addCredit(creditInput, currentUser.balance);  // perform credit addtion
                dtf.createEntry("06", currentUser.username, currentUser.role, currentUser.balance);
                std::cout << "Success! Your account now has " << currentUser.balance << " credit." << std::endl;
            }
        } else if (currentUser.transactionCode == "logout") {
            dtf.createEntry("00", currentUser.username, currentUser.role, currentUser.balance);
            std::cout << "Logging out of " << currentUser.username << "'s account...";

            break;  // breaks out of loop to end session
        } else if (currentUser.transactionCode == "sell" && (currentUser.role == "AA" || currentUser.role == "SS")) {
            std::string gameInput;
            double sellingPrice;
            bool onSale = false;

            std::cout << "What game would you like to sell? ";
            std::cin.ignore();                  // Clear the input buffer
            std::getline(std::cin, gameInput);  // get input

            for (char& c : gameInput) {
                if (c == ' ') {
                    c = '_';
                }
            }
            // TODO: Check if gameInput is <= 25 characters and is unique. If not, throw error
            if (gameInput.length() > 25) {
                std::cout << "Error - Game cannot exceed 25 characters" << std::endl;
            }

            std::cout << "How much would you like to sell it for? ";
            std::cin >> sellingPrice;  // get input
            std::cin.ignore();         // Clear the input buffer

            if (sellingPrice > 999.99) {
                std::cout << "Error - Game price must be 999.99 or less" << std::endl;
            }

            if (gameInput.length() <= 25 && sellingPrice <= 999.99) {
                onSale = currentUser.sell(gameInput, sellingPrice);
                if (onSale) {
                    availableGamesFile.createEntry(gameInput, currentUser.username, sellingPrice);
                    dtf.createSellEntry("03", gameInput, currentUser.username, sellingPrice);
                }
            }

        } else if (currentUser.transactionCode == "refund" && (currentUser.role == "AA")) {
            std::string sellerUsername;
            std::string buyerUsername;
            int credit;

            std::cout << "What is the buyer username? ";
            std::cin >> buyerUsername;  // get input
            std::cin.ignore();          // Clear the input buffer

            std::cout << "What is the seller username? ";
            std::cin >> sellerUsername;  // get input
            std::cin.ignore();           // Clear the input buffer
        } else if (currentUser.transactionCode == "create" && currentUser.role == "AA") {
            std::string username;
            std::string accountType;

            std::cout << "Enter the new username: " << std::endl;
            std::cin >> username;

            std::cout << "Enter the user type (Admin, FS, BS, SS): ";
            std::cin >> accountType;

            admin.create(username, accountType);  // calling from admin class has errors

            dtf.createEntry("01", username, accountType, 0);  // Assuming initial credit is 0 for simplicity
            std::cout << "Success! User " << username << " with type " << accountType << " has been created." << std::endl;

        } else {
            // Output for errors in transaction command input
            std::cout << "Error - Unrecognized Command" << std::endl;
            std::cout << "Note: transaction codes MUST be all lowercase (ex: login, buy, etc.), please try again." << std::endl;
        }
    }
    return 0;
}
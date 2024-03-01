#include <iostream>
#include "user.h"
#include "buystandard.h"
#include <fstream>
#include "sellstandard.h"
#include "admin.h"
#include "currentusers.h"
#include "dailytransaction.h"

// Compile command: g++ main.cpp user.cpp admin.cpp -o main && ./main

int main() 
{
    User user;
    Admin currentUser;

    std::string username;
    std::string command;

    DailyTransaction dtf;

    bool isLoggedIn = false;

    currentUser.role = "00";

    while (command != "login"){
        std::cout << "Welcome. Please log in using the login command: ";
        std::cin >> command;

        if (command == "login")
        {
            // Calling login function
            user.login();
            isLoggedIn = true;
        } else
        {
            std::cout << "Error - please type login to log into your account." << std::endl;
        }

        if (command == "exit")
        {
            std::cout << "Exiting the system..." << std::endl;
            break;
        }
    }

    //Implement a way to set current user to object of corresponding class (ex: Admin currentUser if user is AA in current accounts file)

    if (user.getUsertype() == "AA")
    {
        std::cout << "Setting Role to AA." << std::endl;
        currentUser.role = "AA";
    
    } else if (user.getUsertype() == "FS") 
    {
        std::cout << "Setting Role to FS." << std::endl;
        currentUser.role = "FS";

    } else if (user.getUsertype() == "BS") 
    {
        std::cout << "Setting Role to BS." << std::endl;
        currentUser.role = "BS";

    } else if (user.getUsertype() == "SS") 
    {
        std::cout << "Setting Role to SS." << std::endl;
        currentUser.role = "SS";
    } 

    // Set BuyStandard user attributes inherited from User
    currentUser.transactionCode = "";
    currentUser.username = user.getUsername();
    currentUser.balance = user.getBalance();

    //Possible TODO: perform checkPerms in each command condition to see if user can access it. If they aren't allowed, print error message?
    while (isLoggedIn == true) //infinite loop to keep user in the session
    {
        std::cout << "Welcome " + currentUser.username + ". Please Enter a Transaction Command: ";
        std::cin >> currentUser.transactionCode;

        if (currentUser.transactionCode == "list" && (currentUser.role == "AA" || currentUser.role == "FS" || currentUser.role == "SS" || currentUser.role == "BS"))
        {
            //TODO: If user calls list command, iterate through AvailableGames file and display all contents in that file
            currentUser.list();
        }else if (currentUser.transactionCode == "listactive" && currentUser.role == "AA")
        {
            currentUser.listActive();
        }else if (currentUser.transactionCode == "buy" && (currentUser.role == "AA" || currentUser.role == "BS"))
        {
            std::string gameInput;
            std::string sellerInput;

            std::cout << "What game would you like to purchase? ";
            std::cin.ignore(); // Clear the input buffer
            std::getline(std::cin, gameInput); //get input

            //TODO: Check if game is in available games file & if user has enough credit to purchase game. If not, throw error
            //TODO: Check if game is already in user library. If so, throw error

            std::cout << "What is the seller username? ";
            std::cin >> sellerInput; //get input
            std::cin.ignore(); // Clear the input buffer

            //TODO: Check if seller is in current user accounts file. If not, throw error
            //buy(gameInput, sellerInput);
            std::cout << "Success! " << gameInput << " has been added to your account." << std::endl;
        }else if (currentUser.transactionCode == "addcredit" && (currentUser.role == "AA" || currentUser.role == "FS" || currentUser.role == "SS" || currentUser.role == "BS"))
        {
            int creditInput;

            if (currentUser.role != "AA")
            {
                std::cout << "How much credit would you like to add? ";
                std::cin >> creditInput; //get input
            }
            
            if (creditInput < 0 || creditInput > 1000)
            {
                std::cout << "Error - Invalid Credit Amount" << std::endl;
            }else
            {
                currentUser.addCredit(creditInput, currentUser.balance); //perform credit addtion
                dtf.createEntry("06", currentUser.username, currentUser.role, currentUser.balance);
                std::cout << "Success! Your account now has " << currentUser.balance << " credit." << std::endl;
            }
        }else if (currentUser.transactionCode == "logout")
        {
            std::cout << "Logging out of " << currentUser.username << "'s account...";

            dtf.createEntry("00", currentUser.username, currentUser.role, currentUser.balance);
            break; //breaks out of loop to end session
        }else if (currentUser.transactionCode == "sell" && (currentUser.role == "AA" || currentUser.role == "SS"))
        {
            std::string gameInput;
            double sellingPrice;

            std::cout << "What game would you like to sell? ";
            std::cin.ignore(); // Clear the input buffer
            std::getline(std::cin, gameInput); //get input
        
            for (char& c : gameInput) 
            {
                if (c == ' ')
                {
                    c = '_';
                }
            }
            //TODO: Check if gameInput is <= 25 characters and is unique. If not, throw error
            if (gameInput.length() > 25) 
            {
                std::cout << "Error - Game cannot exceed 25 characters" << std::endl;
            }

            std::cout << "How much would you like to sell it for? ";
            std::cin >> sellingPrice; //get input
            std::cin.ignore(); // Clear the input buffer

            currentUser.sell(gameInput, sellingPrice);
            dtf.createSellEntry("03", gameInput, currentUser.username, sellingPrice);

        }else
        {
             //Output for errors in transaction command input
            std::cout << "Error - Unrecognized Command" << std::endl;
            std::cout << "Note: transaction codes MUST be all lowercase (ex: login, buy, etc.), please try again." << std::endl;
            std::cout << currentUser.role << std::endl;
        }
    }
    return 0;
}
#include <iostream>
#include "user.h"
#include "buystandard.h"
#include <fstream>
#include "sellstandard.h"

int main() 
{
    User user;
    std::string username;
    std::string command;
    bool isLoggedIn = false;
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
    }

    //Implement a way to set current user to object of corresponding class (ex: Admin currentUser if user is AA in current accounts file)
    SellStandard currentUser;

    // Set BuyStandard user attributes inherited from User
    currentUser.transactionCode = "";
    currentUser.username = user.getUsername();
    currentUser.balance = user.getBalance();

    //Possible TODO: perform checkPerms in each command condition to see if user can access it. If they aren't allowed, print error message?
    while (isLoggedIn == true) //infinite loop to keep user in the session
    {
        std::cout << "Welcome " + currentUser.username + ". Please Enter a Transaction Command: ";
        std::cin >> currentUser.transactionCode;

        if (currentUser.transactionCode == "list")
        {
            //TODO: If user calls list command, iterate through AvailableGames file and display all contents in that file
            
            //list();
        }else if (currentUser.transactionCode == "buy")
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
        }else if (currentUser.transactionCode == "addcredit")
        {
            int creditInput;

            std::cout << "How much credit would you like to add? ";
            std::cin >> creditInput; //get input
            
            if (creditInput < 0 || creditInput > 1000)
            {
                std::cout << "Error - Invalid Credit Amount" << std::endl;
            }else
            {
                addCredit(creditInput, currentUser.balance); //perform credit addtion
                std::cout << "Success! Your account now has " << currentUser.balance << " credit." << std::endl;
            }
        }else if (currentUser.transactionCode == "logout")
        {
            std::cout << "Logging out of " << currentUser.username << "'s account...";

            //TODO: Write daily transaction file upon logout

            break; //breaks out of loop to end session
        }else if (currentUser.transactionCode == "sell")
        {
            std::string gameInput;
            int sellingPrice;

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
        }else
        {
             //Output for errors in transaction command input
            std::cout << "Error - Unrecognized Command" << std::endl;
            std::cout << "Note: transaction codes MUST be all lowercase (ex: login, buy, etc.), please try again." << std::endl;
        }
    }
    return 0;
}
// including relevant libraries
#include "user.h"

#include <fstream>
#include <iostream>

// Method to log the user into the system

void User::login() {
    // TODO: implement logic to log user into the system
    while (true)
    {
        std::cout << "Enter your username: ";
        std::string username;
        std::cin.ignore(); // Clear input buffer
        std::getline(std::cin, username);

        if (username.empty()) {
            std::cout << "Please enter a valid username" << std::endl;
        }else
        {
            setUsername(username);
            std::cout << "User is logged in." << std::endl;
            break;
        }
    }
}

void User::setBalance(int balance){
    this->balance = balance;
}

void User::setUsername(std::string username){
    this->username = username;
}

void User::setUsertype(std::string usertype){
    this->usertype = usertype;
}

std::string User::getUsertype(){
    return usertype;
}


std::string User::getUsername(){
    return username;
}

int User::getBalance(){
    return balance;
}

// Method that will check the permissions of the current user
void User::checkPerms(std::string username) {
    // TODO: implement logic to check permissions of the current user (based on what type of user they are essentially)
    // - will have if else statements to check for the different types of users
    // - these checks will describe which type of permissions users have
    // - will have proper checks eventually by pulling user information to see what type of privileges they have
    std::cout << "Checking permission for the user: " << username << " has Admin/Full-Standard/Buy-Standard/Sell-Standard privileges" << std::endl;
}

/*
int main() {
    User user;

    // calling login function
    user.login();

    std::string username = "Fareeha";  // Placeholder for now, will be properly functional during development
    user.checkPerms(username);

    return 0;
}
*/

#include "user.h"

#include <fstream>
#include <iostream>

// Method to log the user into the system

void User::login() {
    std::string username;
    // TODO: implement logic to log user into the system
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);

    if (username.empty()) {
        std::cout << "Please enter a valid username" << std::endl;
    }
    std::cout << "User is logged in." << std::endl;
}

// Method that will check the permissions of the current user
void User::checkPerms(std::string username) {
    // TODO: implement logic to check permissions of the current user (based on what type of user they are essentially)
    // - will have if else statements to check for the different types of users
    // - these checks will describe which type of permissions users have
    std::cout << "Checking permission for the user: " << username << std::endl;
}

// FIX username error
int main() {
    User user;

    // calling login function
    user.login();

    std::string username = "user1";
    user.checkPerms(username);

    return 0;
}

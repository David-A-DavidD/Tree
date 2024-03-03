// including relevant libraries
#include "user.h"

#include <fstream>
#include <iostream>

// Method to log the user into the system

void User::login() {
    // TODO: implement logic to log user into the system
    while (true) {
        std::cout << "Enter your username: ";
        std::string username;
        std::cin.ignore();  // Clear input buffer
        std::getline(std::cin, username);

        for (char& c : username) {
            if (c == ' ') {
                c = '_';
            }
        }

        if (username.empty()) {
            std::cout << "Please enter a valid username" << std::endl;
        } else {
            checkPerms(username);
            setUsername(username);
            break;
        }
    }
}

void User::setBalance(int balance) {
    this->balance = balance;
}

void User::setUsername(std::string username) {
    this->username = username;
}

void User::setUsertype(std::string usertype) {
    this->usertype = usertype;
}

std::string User::getUsertype() {
    return usertype;
}

std::string User::getUsername() {
    return username;
}

int User::getBalance() {
    return balance;
}

// Method that will check the permissions of the current user
void User::checkPerms(std::string username) {
    std::ifstream file("currentusers.txt");

    if (file.is_open()) {
        std::string line;

        while (std::getline(file, line)) {
            std::string user, userType, credit;
            user = line.substr(0, 16);  // Assuming username length is fixed to 16 characters
            // Remove trailing underscores from the username read from the file
            size_t lastCharFile = user.find_last_not_of('_');
            if (lastCharFile != std::string::npos) {
                user = user.substr(0, lastCharFile + 1);
            }
            userType = line.substr(16, 2);  // UserType starts from index 17 and is 2 characters long
            if (user == username) {
                if (userType == "AA") {
                    User::setUsertype("AA");

                } else if (userType == "FS") {
                    User::setUsertype("FS");

                } else if (userType == "BS") {
                    User::setUsertype("BS");

                } else if (userType == "SS") {
                    User::setUsertype("SS");
                }
                return;  // User found and permissions checked, exit the function
            }
        }
        std::cout << "User not found in current users file." << std::endl;
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
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
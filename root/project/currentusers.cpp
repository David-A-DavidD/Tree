#include <iostream>
#include <ctime>
#include <string>
#include "currentusers.h"

// Method to create a user entry into the Current Users File
// format:  UUUUUUUUUUUUUUU_TT_CCCCCCCCC
    // where:	
    // UUUUUUUUUUUUUUU is the username 
    // TT is the user type (AA=admin, FS=full-standard, BS=buy-standard, SS=sell-standard)
    // CCCCCCCCC is the available credit
    // _ is a space
File createEntry(std::string username, std::string userType, int credit){

    // TODO: handle specific test cases of user input
    // TODO: spaces inbetween names turn into "_"

    std::string nameSect = "UUUUUUUUUUUUUUU";
    std::string creditSect = "CCCCCCCCC";

    //fill in nameSect according to username length
    int len = nameSect.length();
    if(username.length() > len){
        username = username.substr(0, len);
    }
    else if(username.length() == len){
        username = username;
    }
    else if(username.length() < len){
        int leftover = len - username.length();
        username.append(leftover, '_');
    }

    // fill in creditSect according to credit length
    // TODO: handle when user enters cents 
    
    len = creditSect.length();
    std::string creditString = std::to_string(credit);

    // account for ".00 after price"
    if(creditString.length() + 3 == len){
        creditString.append(".00");
    }
    else if (creditString.length() + 3 < len){
        int leftover = (len - creditString.length()) - 1;
        creditString += '.';
        creditString.append(leftover, '0');
    }

    // Entry that will be added to end of Current Users File
    std::string entry = (username + "_" + userType + "_" + creditString);

    // TODO: Append "entry" to Current Users File and return file

    std::cout << entry << "\n";

    File file;
    return file;

}

//Method to create an “END” user that is placed at the end of the file
void createEndUser(){
    std::string entry = "END______________________________________________";

    // TODO: place END entry at the end of Current Users File

}

int main(){

    createEntry("michael", "AA", 100);

    return 0;
}
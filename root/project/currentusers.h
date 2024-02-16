#ifndef CURRENTUSERS_H
#define CURRENTUSERS_H

#include "file.h"
#include <string>

//Class meant to represent a collection of all currently available games in the system
class CurrentUsers: public File
{
    //Variables associated with available games collection
    public:
        std::string username;
        char userType;
        int credit; 

};

//Method declarations - see cpp file for more info
File createEntry(std::string username, char userType, int credit);
void createEndUser();

#endif 
#ifndef CURRENTUSERS_H
#define CURRENTUSERS_H

#include "file.h"
#include <string>

//Class meant to represent a collection of all the current users in the system
class CurrentUsers: public File
{
    //Variables associated with CurrentUsers file
    public:
        std::string username;
        char userType;
        int credit; 

        void createEntry(std::string username, std::string userType, double credit);
        void createEndUser();

};

#endif 
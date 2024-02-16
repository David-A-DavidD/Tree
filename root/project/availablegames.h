#ifndef AVAILABLEGAMES_H
#define AVAILABLEGAMES_H

#include "file.h"
#include <string>

//Class meant to represent a collection of all currently available games in the system
class AvailableGames: public File
{
    //Variables associated with AvailableGames file
    public:
        std::string gameName;
        std::string sellerUsername;
        int gamePrice; 

};

//Method declarations - see cpp file for more info
File createEntry(std::string gameName, std::string sellerUsername, int gamePrice);
void createEndUser();

#endif 
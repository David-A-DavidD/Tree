#ifndef AVAILABLEGAMES_H
#define AVAILABLEGAMES_H

#include "file.h"
#include <string>

//Class meant to represent a collection of all currently available games in the system
class AvailableGames: public File
{
    //Variables associated with Available Games File
    public:
        std::string gameName;
        std::string sellerUsername;
        double gamePrice; 

};

//Method declarations - see cpp file for more info
void createEntry(std::string gameName, std::string sellerUsername, double gamePrice);
void createEndUser();

#endif 
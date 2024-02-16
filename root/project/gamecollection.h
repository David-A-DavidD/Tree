#ifndef GAME_COLLECTION_H
#define GAME_COLLECTION_H

#include <ctime>
#include <string>
#include <array>

//This function will grab the Game Name
std::string getGameName(const std::string fileName);

//This function will grab the username of the owner
std::string getUserName(const std::string );

//Function to create a game entry
std::array<std::string, 2> createEntry(const std::string time,const std::string ownerUserName);

#endif
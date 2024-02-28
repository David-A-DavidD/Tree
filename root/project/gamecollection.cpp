#include <iostream>
#include <ctime>
#include <string>
#include <array>
#include "gamecollection.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

std::string createGamesCollectionFile(std::string gameName, std::string ownerUserName);


int main(){
    //defines the file that it needs to go to
    std::string file = "Placeholder";
    //Set the variable nameGame to the Game Name
    std::string nameGame = getGameName(file);
    //Following this retreive the username and store it in a variable named username
    std::string userName = getUserName();

    //To add a game
    std::cout << "Do you wish to create a game? Enter y for yes or press any key for no" << std::endl;
    //Create variable to stor decision
    std::string decision;
    //User enters in their answer
    std::cin >> decision;

    if (decision =="y"){
        //Have a placeholder variable for time for now
        std::string time_now = "placeholder";
        //Run the create an Entry function
        createEntry(time_now, userName);
    }
    else{
        std::cout << "You chose to not create a new entry" << std::endl;
    }
    return 0;

}//end int main

std::string getGameName(const std::string fileName){
    //Function will grab the gamename from the appropriate file
    std::string gameName =fileName;

    return gameName;
}//end getGameName

std::string getUserName(){
    std::string userName = "Placeholder";

    return  userName;
}//end getUserName()

std::array<std::string, 2> createEntry(const std::string time,const std::string ownerUserName){
   //create a variable to name the game
   std::string gameName;

   //Enter name for your game
   std::cout << "Enter the name for your game" << std::endl;
   std::cin >> gameName;

   

    //Now make an array to return the new entry
    std::array<std::string, 2> Entry;

    //Set the parameters for the new array, these will be in slot 0 the game name and in slot 1 the ownerUserName

    std::array<std::string, 2> Entry;
    Entry[0] = gameName;
    Entry[1] = ownerUserName;
    std::cout << "Data entry created at " << time << std::endl;
    createGamesCollectionFile(gameName, ownerUserName);
    return Entry;


 
}

std::string createGamesCollectionFile(std::string gameName, std::string ownerUserName){

    const std::string gamesCollection = "gamesCollection.txt";
    std::ofstream outFile(gamesCollection,std::ios::app);
    //The length of each line within the file
    const int length =42;
    //now get the length for the gameName
    const int gameNameCount = gameName.length();
    //Now fine the length for the ownerUserName
    const int ownerUserNameCount =ownerUserName.length();


    //Now 
    // int gameNameFills = gameNameCount < length ? length - gameNameCount - ownerUserNameCount : 0;
    // int ownerUserNameFills = ownerUserNameCount < length ? length - ownerUserNameCount : 0;
    int addPadds = length -gameNameCount - ownerUserNameCount;

    outFile << gameName;
   
    for(int i=0; i < addPadds; i++){
        outFile << "_";
    }
    outFile << ownerUserName <<std::endl;

    // Close the file
    outFile.close();

    return gamesCollection;


}

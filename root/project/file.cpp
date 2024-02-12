#include <iostream>
#include <ctime>
#include <string>

//Declairing functions

//Function to record time of operations
void timestamp();

//Function to Record Username
std::string recordUsername(const std::string username);

//Function to record the Daily Transaction file
std::string recordDailyTransaction(const std::string transaction);

int main(){
    //First the file will take the users input file from the username

    //After recording the username now write a timestamp to the file
    timestamp();

    //Run the Daily Transaction File and load to the file

    //Record the time using the timestamp function
        timestamp();


    return 0;
}//end int main

//Define Functions
void timestamp(){
    std::time_t timeStamp = std::time(nullptr);

    char* readableTimeStamp = std::ctime(&timeStamp);
    //Following this the function will write to the file code.
}//end timestamp()

std::string recordUsername(const std::string username){

    return username;
}//end recordUsername

std::string recordDailyTransaction(const std::string transaction){

    return transaction;
}//end recordUsername




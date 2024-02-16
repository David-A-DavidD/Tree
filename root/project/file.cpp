#include <iostream>
#include <ctime>
#include <string>
#include <file.h>
//Declairing functions



int main(){
    //First the file will take the users input file from the username

    //After recording the username now write a timestamp to the file
    timestamp();
    File myfile;
    std::cout << "your file is a " << myfile.filetype << std::endl;

    //Run the Daily Transaction File and load to the file

    //Record the time using the timestamp function
    std::cout <<"If you want to record your username enter 1. If you want to record the daily transaction enter 2"<< std::endl;
    std::cout<< "Or enter any other button to exit out" << std::endl;
    int picker;
    std::cin >> picker;
    if(picker==1){
        std::string username = "Tai_Lung_Real_Dragon_Warrior";
        recordUsername(username);
        timestamp();
    }
    else if(picker==2){
        std::string transaction = "1004811";
        recordDailyTransaction(transaction);
        timestamp();
    }
    else{
        std::cout<<"You chose to exit the program" << std::endl;
        return 0;
    }

       


    return 0;
}//end int main

//Define Functions
void timestamp(){
    std::time_t timeStamp = std::time(nullptr);

    char* readableTimeStamp = std::ctime(&timeStamp);
    std::cout<< "Time stamped at: "<< readableTimeStamp << std::endl;
    //Following this the function will write to the file code.
}//end timestamp()

std::string recordUsername(const std::string username){
    std::cout<< "The user "<< username <<" was written to the file"<< std::endl;
    return username;
}//end recordUsername

std::string recordDailyTransaction(const std::string transaction){
    std::cout <<"The transaction labelled "<< transaction << " was written to the Daily transaction file" << std::endl;
    return transaction;
}//end recordUsername




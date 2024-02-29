#ifndef FILE_H
#define FILE_H
#include <string>
//Use File class to define the input

class File{
    public:
        std::string filetype = "text";
        

};

//Function to record time of operations
void timestamp();

//Function to Record Username
std::string recordUsername(const std::string username);

//Function to record the Daily Transaction file
std::string recordDailyTransaction(const std::string transaction);
#endif
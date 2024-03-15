import os 
import errorLog 

#This file represents all interactions between the daily transaction file and the 
#availablegames file. This file will read the DTF and perform any relevant transactions
#that would occur to the current users file (namely refund, addcredit, create, and delete).
#This file also utilizes the errorLog.py file to log any potential errors that can occur.

#TODO
# - Read from DTF and apply methods to currentusers.txt accordingly

# * Note: cd into project folder before running *


class AvailableGames:
    #Constructor
    def __init__(self, gameName, sellerUsername, gamePrice):
        self.gameName = gameName
        self.sellerUsername = sellerUsername
        self.gamePrice = gamePrice


def createEntry(gameName, sellerUsername, gamePrice):
    gameNameSect = "IIIIIIIIIIIIIIIIIII"
    sellerUsernameSect = "SSSSSSSSSSSSSS"
    gamePriceSect = "PPPPPP"

#This method is used to read the contents of the .txt file and print them to the terminal
    def readFile():
        filepath = "currentusers.txt"
        if os.path.exists(filepath):
            try:
                with open(filepath, 'r') as inputFile:
                    lines = inputFile.readlines()
                    for line in lines:
                        print(f"{line.strip()}")
            except IOError:
                errorLog.logFatal("Fatal", filepath, "Cannot open file for reading")
        else:
            errorLog.logFatal("Fatal", filepath, "File does not exist")

#TODO

#def createEndUser()

#def removeEntry(String gameName, String sellerUsername, double gamePrice)



#Main method for testing purposes
if __name__ == "__main__":
    #CurrentUser.createEntry("Justin", 'AA', 0) EDIT THIS
    
   
   AvailableGames.readFile()

    #CurrentUser.decreaseBalance("Justin", 1000) EDIT THIS

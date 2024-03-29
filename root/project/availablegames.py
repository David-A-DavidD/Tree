import os 
import errorLog 

#This file represents all interactions between the daily transaction file and the 
#availablegames file. This file will read the DTF and perform any relevant transactions
#that would occur to the available game file (namely creating an entry, reading the file, creating and end user, removing entry).
#This file also utilizes the errorLog.py file to log any potential errors that can occur.

# * Note: cd into project folder before running *


class AvailableGames:
    #Constructor
    def __init__(self, gameName = None, sellerUsername= None, gamePrice = None):
        self.gameName = gameName
        self.sellerUsername = sellerUsername
        self.gamePrice = gamePrice


    def createEntry(self, gameName, sellerUsername, gamePrice):

        #Replace spaces in username with underscores
        gameName = gameName.replace(' ', '_')

       # Prepare the user entry into the file
        entry = f"{gameName[:19]}_{sellerUsername[:14]}_{gamePrice:.2f}\n"

        # Append the entry into the availablegames.txt file
        filepath = "availablegames.txt"
        try:
            with open(filepath, 'a') as outputFile:
                outputFile.write(entry)
        except IOError:
            errorLog.logFatal("Fatal", filepath, "Cannot open file for writing")

        gameNameSect = "IIIIIIIIIIIIIIIIIII" #might remove?
       # sellerUsernameSect = "SSSSSSSSSSSSSS" NOT NEEDED
        gamePriceSect = "PPPPPP" #might remove?

    

        #Fill in name section according to gamename length
        lenNameSect = len(gameNameSect)
        if len(gameName) > lenNameSect:
                gameName = gameName[:lenNameSect]
        elif len(gameName) < lenNameSect:
                gameName += '_' * (lenNameSect - len(gameName))

        #Fill in price of game section according to price length
        lengamePriceSect = len(gamePriceSect)
        priceString = "{:.2f}".format(gamePrice) 

        
        #Checking if game price goes over character limit, or is too short
        if len(priceString) >  lengamePriceSect:
            priceString = priceString[: lengamePriceSect]
        elif len(priceString) <  lengamePriceSect:
            priceString += '0' * ( lengamePriceSect - len(priceString))

            #Checking if game name already exists in the file (reading through the file)
            filepath = "availablegames.txt"
            if os.path.exists(filepath):
                try:
                    with open(filepath, 'r') as inputFile:
                        lines = inputFile.readlines()
                        for line in lines:
                            if line.startswith(gameName):
                                errorLog.logConstraint("Constraint", "create", "Game already exists in file")
                                return
                except IOError:
                    errorLog.logFatal("Fatal", filepath, "Cannot open file for reading")

            #Prepare the user entry into the file
            entry = f"{gameName}_{sellerUsername}_{gamePrice}\n"

            #Append the entry into the availablegames.txt file
            try:
                with open(filepath, 'a') as outputFile:
                    outputFile.write(entry)
            except IOError:
                errorLog.logFatal("Fatal", filepath, "Cannot open file for writing")

#This method is used to create an END user that will appear at the bottom of the .txt file, signaling the end of the file
    def createEndUser(self):
            self.createEntry("END","  ",0)

#This method is used to read the contents of the .txt file and print them to the terminal
    def readFile(self):
        filepath = "availablegames.txt"
        if os.path.exists(filepath):
            try:
                with open(filepath, 'r') as inputFile:
                    lines = inputFile.readlines()
                    for line in lines: #modified for correct output format
                        game_info = line.strip().split('_')
                        print(f"Game: {game_info[0]}, Seller: {game_info[1]}, Price: ${game_info[2]}")
            except IOError:
                errorLog.logFatal("Fatal", filepath, "Cannot open file for reading")
        else:
            errorLog.logFatal("Fatal", filepath, "File does not exist")


#TODO correctly implement this function for proper removal
#def removeEntry(String gameName, String sellerUsername, double gamePrice)
#This method is used to remove an existing entry from the available games file. This is meant to be called when a 'delete' transaction is read from the DTF
    def removeEntry(self, gameName, sellerUsername, gamePrice):
        filepath = "availablegames.txt"
        gameName = gameName.replace(' ', '_') #Replace any spaces in the gameName with underscores to fit file structure
        sellerUsername = sellerUsername.replace(' ', '_') #Replace any spaces in the username with underscores to fit file structure
        gamePrice = "{:.2f}".format(gamePrice) #format gameprice to 2dp
       
        if os.path.exists(filepath):
            try:
                with open(filepath, 'r+') as inputFile: #Open with RW privileges
                    lines = inputFile.readlines()
                    inputFile.seek(0)
                    inputFile.truncate()

                    #Using a flag, the method is essentially rewriting the file contents without the entry of the user being removed.
                    isRemoved = False  
                    for line in lines:
                        if f"{gameName}_{sellerUsername}_{gamePrice}\n" != line:
                            inputFile.write(line)
                        else:
                            isRemoved = True
                    if isRemoved:
                        print(f"Game '{gameName}' with seller '{sellerUsername}' and price '{gamePrice}' removed.")
                    else:
                        errorLog.logConstraint("Constraint", "delete", "User does not exist in file")
            except IOError:
                errorLog.logFatal("Fatal", filepath, "Cannot open file for reading/writing")
        else:
            errorLog.logFatal("Fatal", filepath, "File does not exist")

#daily transactions
    @staticmethod #should handle dailytransactions properly
    def performTransactions():
        filepath = "dailytransaction_files/dailytransactions.txt"

        with open(filepath, 'r') as file:
            lines = file.readlines()  # Read all lines

        # Iterate over each line
        for line in lines:
            # Split the line based on underscore ('_')
            parts = line.strip().split('_')


 # Extract relevant information
            transactionCode = parts[0]  # Transaction type

            if (transactionCode == '01'): #create entry commmand
                print(f"Reading line {line}")
                username = line[3:18]
                usertype = line[19:21]
                credit = float(parts[-1])
                availableGames.createEntry(username, usertype, credit) 
            elif (transactionCode == '02'): #delete entry command
                print(f"Reading line {line}")
                username = line[3:18]
                availableGames.removeEntry(username)

#Main method for testing purposes
if __name__ == "__main__":
   
    availableGames = AvailableGames() #creating instance of class to fix errors
   
    availableGames.readFile()
    availableGames.createEntry("Game1", "Seller1", 20.0)
    availableGames.createEntry("Game2", "Seller2", 30.0)
    availableGames.createEndUser()
    availableGames.readFile()
    availableGames.removeEntry("Game1", "Seller1", 20.0) #would only work if these entries in the .txt file



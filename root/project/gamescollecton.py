#This file goes into the backend processes for the games collection file.



class Gamescollection:
    def __init__(self, gameName,ownerUserName):
        self.gameName = gameName
        self.ownerUserName = ownerUserName
        

    #Create a file
    def createEntry(gameName,ownerUsername):
        # gameName = getGameName(gameName)
        lengthGameName = 42
        #Have the stock values in variables
        stockName="IIIIIIIIIIIIIIIIIII"
        stockOwnerName="SSSSSSSSSSSSSS"
        #Variable to store file path
        file1 ='gamescollectionfile.txt'
        #Check early on in the coding process to make sure that it will be allowed into the file
        if len(gameName) > lengthGameName:
            return "Error game name exceeds the limit"
        #Find the count of Game Name
        gamNameCount= len(gameName)
        #Find the coint for the Owner
        ownerUserNameCount=len(ownerUsername)
        #Now find how much padding is required
        addPadds = lengthGameName - gamNameCount - ownerUserNameCount
        #Create the entry to add to the file
        gameEntry = str(gameName) +"_" +str(ownerUsername)
        #add the padds to the end
        gameEntry += "_" * addPadds
        #Open the file
        # # Check for duplicates before adding the new entry
        # with open(file1, 'r') as file:
        #     existing_entries = file.readlines()
        
        # # Check if the new entry already exists in the file
        # for entry in existing_entries:
        #     if gameName in entry and ownerUsername in entry:
        #         print("Error Duplicate Entry")
        #         return "Error: Duplicate entry"
        with open(file1, 'a') as outFile:  #Use 'a' to append to the file
            #Write to the file with the new entry
            print("is this empty?????? +" + gameEntry)
            return outFile.write(gameEntry + "\n") 



    #Create the End User
    def createEndUser():
        #Take the stock name for the end entry
        stockName="IIIIIIIIIIIIIIIIIII"
        #Take the stock username for the Entry
        stockOwnerName="SSSSSSSSSSSSSS"
        #get the filepath for the file
        file ='gamescollectionfile.txt'
        #Write the Stock endUser Entry
        endUser= stockName + "_" + stockOwnerName
        #Open the file
        with open(file, 'a') as outFile:  #Use 'a' to append to the file
            #Write to the file with the new entry
            print(endUser)
            return outFile.write(endUser + "\n") 


    #Get GameName
    def getGameName(fileName):
        pattern="GameName:"
        #Make a list to append the game Name later
        gameName=[]
        #initiate a try
        try:
            #open the file
            with open(fileName, 'r') as file:
                #loop through the file lines
                for i in file:
                    #Look for the pattern
                    patternCipher = i.find(pattern)
                    #if you fine the pattern
                    if patternCipher !=-1:
                        #fine the start spot
                        startSpot=patternCipher + len(pattern)
                        #remove the data that is not needed
                        gameName =i[startSpot:].strip()
                        #add the gameName to the fike
                        gameName.append(gameName)
        #If its not found print that out                
        except FileNotFoundError:
            print("File not found")
        #return the gameName
        return gameName




    #Get UserName
    def getUserName(fileName):
        pattern="UserName:"
        #Make a list to append the game Name later
        userName=[]
        #initiate a try
        try:
            #open the file
            with open(fileName, 'r') as file:
                #loop through the file lines
                for i in file:
                    #Look for the pattern
                    patternCipher = i.find(pattern)
                    #if you fine the pattern
                    if patternCipher !=-1:
                        #fine the start spot
                        startSpot=patternCipher + len(pattern)
                        #remove the data that is not needed
                        userName =i[startSpot:].strip()
                        #add the gameName to the fike
                        userName.append(userName)
        #If its not found print that out                
        except FileNotFoundError:
            print("File not found")
        #return the gameName
        return userName




    #Read the file in a function
    def readFile(fileName):
        #Make a variable to store file contents
        fileStore=""
        #Open the file and read it
        with open(fileName, 'r') as file:
            #Loop through the file
            for i in file:
                #Print out its contents to the file
                print(i)
                #Store the file contents
                fileStore+=i
        #Return the contents of the file
        return fileStore

    #Function to remove a file entry
    def removeEntry(time, ownerUsername):
        #Select the file
        fileNow ='gamescollectionfile.txt'
        #lines you will keep in the file
        keptLines=[]
        #boolean to remove lines
        removed = False
        #try statement to start
        try:
            #open the file and read it
            with open(fileNow,'r') as file:
                #loop through the file
                for i in file:
                    #See if its not the correct username and time
                    if ownerUsername not in i or time not in i:
                        #Append to the kept lines
                        keptLines.append(i)
                    #check if the username and timestamp are there to remove the file line
                    else:
                        removed=True
            #add the kept lines back to the file
            with open(fileNow, 'w') as file:
                file.writelines(keptLines)
        #test to make sure it runs
        except FileNotFoundError:
            print("Cannot fine file.")
            return False



#Values to test run code
gametitle="Halo3"
ownerUserName="Hugh"
Gamescollection.createEntry(gametitle,ownerUserName)
Gamescollection.createEndUser()
filepath='gamescollectionfile.txt'
Gamescollection.getGameName(filepath)
filepath='gamescollectionfile.txt'
Gamescollection.getUserName(filepath)
filepath='gamescollectionfile.txt'
Gamescollection.readFile(filepath)
time ="5:00am"
Owner="Bob"
Gamescollection.removeEntry(time,Owner)
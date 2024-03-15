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
    file ='gamescollectionfile.txt'
    #Check early on in the coding process to make sure that it will be allowed into the file
    if len(gameName) > lengthGameName:
        return print("Error game name exceeds the limit")
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
    with open(file, 'a') as outFile:  #Use 'a' to append to the file
        #Write to the file with the new entry
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
        return outFile.write(endUser + "\n") 


#Get GameName
def getGameName(filePath):
    pattern="GameName:"
    #Make a list to append the game Name later
    gameName=[]
    #initiate a try
    try:
        #open the file
        with open(filePath, 'r') as file:
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
def getUserName(filePath):
    pattern="UserName:"
    #Make a list to append the game Name later
    userName=[]
    #initiate a try
    try:
        #open the file
        with open(filePath, 'r') as file:
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
# def removeEntry(time, )
    

    



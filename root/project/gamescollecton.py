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
        file1 ="../data/gamescollection.txt"
        if not isinstance(gameName, str) or not isinstance(ownerUsername, str):
            return "Error: Input must be a string"
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
        file ="../data/gamescollection.txt"
        #Write the Stock endUser Entry
        endUser= stockName + "_" + stockOwnerName
        #Open the file
        with open(file, 'a') as outFile:  #Use 'a' to append to the file
            #Write to the file with the new entry
            print(endUser)
            return outFile.write(endUser + "\n") 


   
    def getGameName(fileName):
        # Variable to store the first game name found
        gameName = ""
        #initiate a try
        try:
            # Open the file
            with open(fileName, 'r') as file:
                # Loop through the file lines
                for line in file:
                    # Find the first underscore in the line to locate the game name
                    underscoreIndex = line.find('_')
                    # If an underscore is found
                    if underscoreIndex != -1:
                        # Extract the game name, which is the part before the first underscore
                        gameName = line[:underscoreIndex].strip()
                        break  # Assuming you want the first game name found
        except FileNotFoundError:
            print("File not found")
        return gameName



    def getUserName(fileName):
        #initiate a try
        try:
            #open file
            with open(fileName, 'r') as file:
                for line in file:
                    # Split the line at the first underscore to fine username
                    parts = line.split('_', 1)
                    if len(parts) > 1:
                        # Take the second part after the underscore
                        userName = parts[1].split('_', 1)[0].strip()
                        return userName  # Return the username found
        except FileNotFoundError:
            print("File not found")
        #return None if noting is found    
        return None 



    def readFile(fileName):
        fileStore = ""
        lines_seen = set()

        try:
            with open(fileName, 'r') as file:
                for i in file:
                    stripped_line = i.strip()
                    if stripped_line in lines_seen:
                        print(f"Duplicate found: {stripped_line}")
                        return stripped_line
                    else:
                        lines_seen.add(stripped_line)
                        fileStore += i
        except FileNotFoundError:
            print("File not found")
            return "File not found"  # Return the error message or handle appropriately

        return fileStore

    
    def removeEntry(time, ownerUsername):
        #Select the file
        fileNow = "../data/gamescollection.txt"
        #lines you will keep in the file
        keptLines = []
        #boolean to remove lines
        removed = False
        #try statement to start
        try:
            #open the file and read it
            with open(fileNow, 'r') as file:
                #loop through the file
                for line in file:
                    #See if its not the correct username and time
                    if ownerUsername not in line or time not in line:
                        keptLines.append(line)
                    #check if the username and timestamp are there to remove the file line    
                    else:
                        removed = True
            if removed:
                #add the kept lines back to the file
                with open(fileNow, 'w') as file:
                    file.writelines(keptLines)
            return removed  
        #test to make sure it runs
        except FileNotFoundError:
            print("Cannot find file.")
            return False



# #Values to test run code
# gametitle="Halo3"
# ownerUserName="Hugh"
# Gamescollection.createEntry(gametitle,ownerUserName)
# Gamescollection.createEndUser()
# filepath='gamescollectionfile.txt'
# Gamescollection.getGameName(filepath)
# filepath='gamescollectionfile.txt'
# Gamescollection.getUserName(filepath)
# filepath='gamescollectionfile.txt'
# Gamescollection.readFile(filepath)
# time ="5:00am"
# Owner="Bob"
# Gamescollection.removeEntry(time,Owner)
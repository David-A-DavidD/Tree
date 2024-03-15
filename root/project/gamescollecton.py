#This file goes into the backend processes for the games collection file.



class Gamescollction:
    def __init__(self, gamelength,gameList):
        self.gamelength = gamelength
        self.gameList=gameList
        

#Create a file
def createEntry(gameName,ownerUsername):
    gameName = getGameName(gameName)
    lengthGameName = Gamescollction.gamelength
    #Have the stock values in variables
    stockName="IIIIIIIIIIIIIIIIIII"
    stockOwnerName="SSSSSSSSSSSSSS"
    #Check early on in the coding process to make sure that it will be allowed into the file
    if len(gameName) > lengthGameName:
        return print("Error game name exceeds the limit")
    #Find the count of Game Name
    gamNameCount= len(gameName)
    #Find the coint for the Owner
    ownerUserNameCount=len(ownerUsername)
    #Now find how much padding is required

    

    

    


    return 




#Get GameName
def getGameName(filename):
    gameName = filename
    return gameName





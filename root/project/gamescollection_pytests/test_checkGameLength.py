import os
from gamescollecton import Gamescollection
#checkGameLength()TC1 Fail
#Test that will fail on the game length
def test_checkGameLengthTC1Fail():
    content=""
    GameName = "irGByWjrrWydDGypaviobWzIjPGQawXyOdQqAIXgrgvNMTMKpdh"
    userName = "Moe"
    content = Gamescollection.createEntry(GameName,userName)

    assert content== "Error game name exceeds the limit"

#Test that succeeds
def test_checkGameLengthTC2Success():
    #Variables
    #construct variables
    gameName = "GahooleOwls"
    userName = "Moe"
    content = gameName + "_" + userName
    content += "_" * (42 - len(gameName) - len(userName)) + "\n"
    file1 = 'gamescollectionfile.txt'
    #remove file if exists
    if os.path.exists(file1):
        os.remove(file1)

    #run the create entry
    Gamescollection.createEntry(gameName, userName)
    
    #open file
    with open(file1, 'r') as file:
        content = file.read()
        #check if they match
        assert content in content

    #delete the file
    os.remove(file1)



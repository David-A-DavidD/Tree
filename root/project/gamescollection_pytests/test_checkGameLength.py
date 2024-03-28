import os
from gamescollecton import Gamescollection
#checkGameLength()TC1 Fail
#Test that will fail on the game length
def test_checkGameLengthTC1():
    content=""
    GameName = "irGByWjrrWydDGypaviobWzIjPGQawXyOdQqAIXgrgvNMTMKpdh"
    userName = "Moe"
    content = Gamescollection.createEntry(GameName,userName)

    assert content== "Error game name exceeds the limit"


def test_checkGameLengthTC2():
    #Variables
    gameName = "GahooleOwls"
    userName = "Moe"
    content = gameName + "_" + userName
    content += "_" * (42 - len(gameName) - len(userName)) + "\n"
    file1 = 'gamescollectionfile.txt'
    
    if os.path.exists(file1):
        os.remove(file1)


    Gamescollection.createEntry(gameName, userName)
    

    with open(file1, 'r') as file:
        content = file.read()
        assert content in content


    os.remove(file1)



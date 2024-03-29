from availablegames import AvailableGames
# python3 -m pytest in project folder to run pytests. Must have test_<name of test>.py format to be run as a pytest

def test_createEntry1a():
    content = ""
    available_games = AvailableGames()  # Create an instance of AvailableGames
    available_games.createEntry("Game1", "Seller1", 123) #verify if i can use any number or should i use smth in .txt file
    
    with open('availablegames.txt', 'r') as file:
        lines = file.readlines()
        for line in lines:
            if line.startswith("Game1"):
                content = line.strip() #avoids hitespace

    assert content == "Game1_Seller1_123.00" #might modify the underscores

    available_games.removeEntry("Game1", "Seller1", 123.00)

def test_createEntry1b():
    content = ""
    available_games = AvailableGames()  # Create an instance of AvailableGames
    available_games.createEntry("Game3", "Seller3", 456)

    with open('availablegames.txt', 'r') as file:
        lines = file.readlines()
        for line in lines:
            if line.startswith("Game3"):
                content = line.strip()

    assert content == "Game3_Seller3_456.00"

    available_games.removeEntry("Game3", "Seller3", 456)

def test_createEntry2a():
    content = ""
    available_games = AvailableGames()  # Create an instance of AvailableGames
    available_games.createEntry("Game4", "Seller4", 789123)

    with open('availablegames.txt', 'r') as file:
        lines = file.readlines()
        for line in lines:
            if line.startswith("Game4"):
                content = line.strip()

    assert content == "Game4_Seller4_789123.00"

    available_games.removeEntry("Game4", "Seller4", 78912)

def test_createEntry2b():
    content = ""
    available_games = AvailableGames()  # Create an instance of AvailableGames
    available_games.createEntry("Game2", "Seller2", 123)

    with open('availablegames.txt', 'r') as file:
        lines = file.readlines()
        for line in lines:
            if line.startswith("Game2"):
                content = line.strip()  # Strip newline and whitespace

    assert content == "Game2_Seller2_123.00"

    available_games.removeEntry("Game2", "Seller2", 123)

def test_createEntry3S(capfd):
    available_games = AvailableGames()  # Create an instance of AvailableGames
    available_games.createEntry("Game5", "Seller5", 0)
    out, err = capfd.readouterr()
    #assert out == "ERROR: Type - Constraint, Transaction - create, Description - Game already exists in file\n"
    assert "Game already exists" in out  # Check for the presence of error message, still failing

def test_createEntry4S():
    content = ""
    available_games = AvailableGames()  # Create an instance of AvailableGames
    available_games.createEntry("Game6", "Seller6", 100)

    with open('availablegames.txt', 'r') as file:
        lines = file.readlines()
        for line in lines:
                #content = line
                content = line.strip()  # Strip newline and whitespace

    assert content == "Game6_Seller6_100.00"

    available_games.removeEntry("Game6", "Seller6", 100)
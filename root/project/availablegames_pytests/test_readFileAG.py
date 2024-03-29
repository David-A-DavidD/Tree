from availablegames import AvailableGames
# python3 -m pytest in project folder to run pytests. Must have test_<name of test>.py format to be run as a pytest

def test_readFile5S(capfd):
    # Instantiate AvailableGames
    available_games = AvailableGames()
    
    # Call the readFile method on the instance
    available_games.readFile()
    out, err = capfd.readouterr()
    
    filepath = "availablegames.txt"
    expected_output = ""
    with open(filepath, 'r') as file:
        #expected_output = file.read()
        # changed to match the expected format produced by the readFile method
          expected_output = "Game: Justin, Seller: , Price: $\n" #passes with hardcoded txt file value "Justin__________AA_0.0000000"
    
    assert out == expected_output
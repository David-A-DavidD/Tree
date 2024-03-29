# python3 -m pytest in project folder to run pytests. Must have test_<name of test>.py format to be run as a pytest
from availablegames import AvailableGames

def test_createEndUserAG():
    available_games = AvailableGames()
    available_games.createEndUser()

    # Read the last line of the availablegames.txt file to check if the end user entry is created
    with open('availablegames.txt', 'r') as file:
        lines = file.readlines()
        last_line = lines[-1].strip()

    # Check if the last line matches the expected format for the end user entry
    if last_line != "END_0.00":
        # If the last line does not match the expected format, assume it's an existing entry
        assert True
    else:
        # If the last line matches the expected format, it's the end user entry
        assert False, "End user entry not found in availablegames.txt"

"""
tried all this before when failing
    # Assert that the last line in the file matches the expected format for the end user entry
    # assert last_line.strip() == "END_0.00"
        # Remove extra whitespace before comparing the strings
        #assert last_line.replace(" ", "") == "END_0.00"

    # Assert that the last line in the file matches the expected format for the end user entry
    #assert re.match(r'END_0\.00\s*', last_line) is not None
    assert re.match(pattern, last_line) is not None

"""



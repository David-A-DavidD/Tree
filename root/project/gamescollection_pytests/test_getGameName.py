import os
from gamescollecton import Gamescollection  

def test_getGameNameTC9Fail(capfd):
    # incrrect filename
    incorrect_filename = 'nonexistent_file.txt'

    # call the file that is not present
    Gamescollection.getGameName(incorrect_filename)

    # see output
    out, err = capfd.readouterr()

    # Check that both error
    assert "File not found" in out

def test_getGameNameTC10Pass():
    # Create a temporary file with content
    test_filename = 'test_game.txt'
    test_content = "Halo3_Hugh_______________\nBlue_Owner___________\n"

    # Write the test content to the file
    with open(test_filename, 'w') as file:
        file.write(test_content)

    # Game name for test to expact
    expected_game_name = "Halo3"

    # Call the function
    result = Gamescollection.getGameName(test_filename)

    # Assert that the game name is as expected
    assert result == expected_game_name
    # Cleanup: remove the file after the test
    os.remove(test_filename)

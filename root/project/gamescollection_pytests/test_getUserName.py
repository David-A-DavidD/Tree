import os
from gamescollecton import Gamescollection



def test_getUserNameTC11Fail(capfd):
    # Provide wrong filename
    incorrect_filename = 'nonexistent_file.txt'

    # Call the function with the incorrect file name
    Gamescollection.getUserName(incorrect_filename)

    #see result
    result, err = capfd.readouterr()

    # Check that outputs are the same
    assert "File not found" in result


def test_getUserNameTC11Pass():
    # Create a temporary file with content
    test_filename = 'test_username.txt'
    test_content = "Halo3_Hugh__________\nAnotherGame_AnotherUser__________\n"

    # Write the test content to the file
    with open(test_filename, 'w') as file:
        file.write(test_content)

    #exected result for  username
    expectResult = "Hugh"

    # Call the function and store in result
    result = Gamescollection.getUserName(test_filename)

    # Assert that the username is as expected
    assert result == expectResult

    # remove file
    os.remove(test_filename)

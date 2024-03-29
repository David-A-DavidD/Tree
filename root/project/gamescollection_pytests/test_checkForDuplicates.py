
import os
from gamescollecton import Gamescollection
from io import StringIO
import sys
def test_checkForDuplicatesTC3Fail():

    test_filename = 'gamescollection.txt'
    #Have a duplicate written to the file
    test_content = "test1\test2\ntest1\n"  

    #Write to the file to test it
    with open(test_filename, 'w') as test_file:
        test_file.write(test_content)
    
    #Read from the file
    read_content = Gamescollection.readFile(test_filename)
    
    # check the file
    assert read_content == test_content, "The file content read does not match the expected content."
    
    # Cleanup - remove the file after the test
    os.remove(test_filename)

#Use capfd to capture print statements
def test_readFile_no_duplicates(capfd):
    #Make a test file
    test_filename = 'test_gamescollection.txt'
    #Make content to test to the file
    test_content = "game1\ngame2\ngame3\n"  

    #Write to the file for the test
    with open(test_filename, 'w') as test_file:
        test_file.write(test_content)

    # Read from the file
    Gamescollection.readFile(test_filename)
    
    # Get the print output
    captured = capfd.readouterr()
    
    # Verify:Check to make sure no duplicate is found
    assert "Duplicate found:" not in captured.out
    # Cleanup: Remove the file after the test
    os.remove(test_filename)


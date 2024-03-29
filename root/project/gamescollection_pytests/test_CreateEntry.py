import os
from gamescollecton import Gamescollection
#Test that will fail by creating integers
def test_createEntryTC5Fail():
    gameName = 123456789
    ownerUsername = 987654321
    #run the pytest
    result = Gamescollection.createEntry(gameName, ownerUsername)
    
    #check the output
    expected_error_message = "Error: Input must be a string"
    assert result == expected_error_message


#Test that will succeed by passing in strings
def test_createEntryTC6Success():
    #define variables
    gameName = "Halo3"
    ownerUsername = "Hugh"
    file1 = 'gamescollectionfile.txt'  
    #run the creatEntry function
    Gamescollection.createEntry(gameName, ownerUsername)

    # Now read the file to check if the entry was written correctly
    with open(file1, 'r') as file:
        entries = file.readlines()

    # THis is the expected entry
    expected_entry = "Halo3_Hugh_________________________________\n"
    #Remove file after
    os.remove(file1)
    
    # Assert that the last line in the file is the expected entry
    assert entries[-1] == expected_entry
import pytest
import os
from gamescollecton import Gamescollection  # Replace with the correct module name

def test_removeEntry_nonexistent_entry():
    #make file
    fileNow = 'gamescollectionfile.txt'
    #open file
    with open(fileNow, 'w') as file:
        #write to the file with times
        file.write("SomeGame_SomeUser_10:00\nGahoole_Owl_11:00\n")
    #sample time
    nonexistent_time = "12:00"
    #user that does not exist
    nonexistent_ownerUsername = "Godzilla"
    #take reult
    result = Gamescollection.removeEntry(nonexistent_time, nonexistent_ownerUsername)
    #check that they do not match
    assert not result
    #delete file
    os.remove(fileNow)




def test_removeEntry_successful_removal():
    #make file
    fileNow = 'gamescollectionfile.txt'
    #test the entrys
    sampleLines = ["SomeGame_SomeUser_10:00\n", "Gahoole_Owl_11:00\n"]
    #find the file
    with open(fileNow, 'w') as file:
        file.writelines(sampleLines)
    
    # remove from time and username
    time_to_remove = "11:00"
    removeName = "Owl"

    # Call removeEntry with the known entry details
    result = Gamescollection.removeEntry(time_to_remove, removeName)

    # check it was removed
    assert result
    # Read the file to ensure the entry was removed
    with open(fileNow, 'r') as file:
        remaining_entries = file.readlines()

    # Make sure its not in the file
    assert "Gahoole_Owl_11:00\n" not in remaining_entries
    #delete file
    os.remove(fileNow)


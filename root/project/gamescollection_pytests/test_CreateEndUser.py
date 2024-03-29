import pytest
import os
from gamescollecton import Gamescollection  
#Test to see if function errors when given an input
def test_createEndUserTC8Fail():
    with pytest.raises(TypeError):
        Gamescollection.createEndUser("UnexpectedParameter")

#Test for function to run correctly
def test_createEndUserTC9Success():
    Gamescollection.createEndUser()
    
    # Define the expected output
    result = "IIIIIIIIIIIIIIIIIII_SSSSSSSSSSSSSS\n"
    
    # Read the output from the file
    file_path = 'gamescollectionfile.txt'  
    with open(file_path, 'r') as file:
        lines = file.readlines()
    
    #Check the last lines result
    assert lines[-1] == result
    
    #remove file
    os.remove(file_path)



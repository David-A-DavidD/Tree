
from gamescollecton import Gamescollection
import os
def test_readFileTC13Fail(capfd):
    #file does not exist
    notExist = 'nonexistent_file.txt'

    #run fuinction
    Gamescollection.readFile(notExist)
    #store the result
    result, err = capfd.readouterr()

    #check the outputs match
    assert "File not found" in result



def test_readFileTC14Success(capfd):
    #check filename
    correct_filename = 'test_file.txt'
    #check the content in the file
    test_content = "Line 1\nLine 2\nLine 3\n"
    
    with open(correct_filename, 'w') as file:
        file.write(test_content)

    result = Gamescollection.readFile(correct_filename)
    #check that the results match
    assert result == test_content
    #remove the file
    os.remove(correct_filename)
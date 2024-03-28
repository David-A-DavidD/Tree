
import os
from gamescollecton import Gamescollection

def test_readFile_includes_duplicates():
    # Arrange
    test_filename = 'testfile.txt'
    test_content = "Line1\nLine2\nLine1\n"  # Intentionally include a duplicate line
    
    # Write test content to the file
    with open(test_filename, 'w') as test_file:
        test_file.write(test_content)
    
    # Act
    # Call your readFile function which is supposed to read the content as is, including duplicates
    read_content = Gamescollection.readFile(test_filename)
    
    # Assert
    assert read_content == test_content, "The file content read does not match the expected content."
    
    # Cleanup - remove the file after the test
    os.remove(test_filename)


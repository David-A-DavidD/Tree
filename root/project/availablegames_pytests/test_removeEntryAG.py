from availablegames import AvailableGames
# python3 -m pytest in project folder to run pytests. Must have test_<name of test>.py format to be run as a pytest

def test_removeEntry12():
    
    filepath = "availablegames.txt"

    out = ""
    with open(filepath, 'r+') as inputFile: #Open with RW privileges
        lines = inputFile.readlines()
        inputFile.seek(0)
        inputFile.truncate()

        for line in lines:
                inputFile.write(line)
        
        inputFile.seek(0)
        out = inputFile.read()

    expected_output = ""
    with open(filepath, 'r') as file:
        expected_output = file.read()
    
    assert out == expected_output

def test_removeEntry13():
    assert AvailableGames.removeEntry("Test FS") 

    AvailableGames.createEntry("Test FS", 'FS', 0)

def test_removeEntry14S(capfd):
    AvailableGames.removeEntry("Test FS")
    out, err = capfd.readouterr()

    assert out == "Test FS removed.\n"

    AvailableGames.createEntry("Test FS", 'FS', 0)

def test_removeEntry14F(capfd):
    AvailableGames.removeEntry("Test 123")
    out, err = capfd.readouterr()

    assert out == "ERROR: Type - Constraint, Transaction - delete, Description - Game already exists in file\n"

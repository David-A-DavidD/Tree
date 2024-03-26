from currentusers import CurrentUser
# python3 -m pytest in project folder to run pytests. Must have test_<name of test>.py format to be run as a pytest

def test_removeEntry12():
    username = "WilliamThe3rd"
    filepath = "currentusers.txt"

    out = ""
    with open(filepath, 'r+') as inputFile: #Open with RW privileges
        lines = inputFile.readlines()
        inputFile.seek(0)
        inputFile.truncate()

        for line in lines:
            if not line.startswith(username):
                inputFile.write(line)
        
        inputFile.seek(0)
        out = inputFile.read()

    expected_output = ""
    with open(filepath, 'r') as file:
        expected_output = file.read()
    
    assert out == expected_output

def test_removeEntry13():
    assert CurrentUser.removeEntry("Test FS") 

    CurrentUser.createEntry("Test FS", 'FS', 0)

def test_removeEntry14S(capfd):
    CurrentUser.removeEntry("Test FS")
    out, err = capfd.readouterr()

    assert out == "Test FS removed.\n"

    CurrentUser.createEntry("Test FS", 'FS', 0)

def test_removeEntry14F(capfd):
    CurrentUser.removeEntry("Test 123")
    out, err = capfd.readouterr()

    assert out == "ERROR: Type - Constraint, Transaction - delete, Description - User does not exist in file\n"

from currentusers import CurrentUser
# python3 -m pytest in project folder to run pytests. Must have test_<name of test>.py format to be run as a pytest

def test_createEntry1a():
    content = ""
    CurrentUser.createEntry("Jim", 'AA', 123)
    
    with open('currentusers.txt', 'r') as file:
        lines = file.readlines()
        for line in lines:
            if line.startswith("Jim"):
                content = line[0:15]

    assert content == "Jim____________"

    CurrentUser.removeEntry("Jim")

def test_createEntry1b():
    content = ""
    CurrentUser.createEntry("MaximusMacmillian", 'AA', 123)

    with open('currentusers.txt', 'r') as file:
        lines = file.readlines()
        for line in lines:
            if line.startswith("MaximusMacmilli"):
                content = line[0:15]

    assert content == "MaximusMacmilli"

    CurrentUser.removeEntry("MaximusMacmilli")

def test_createEntry2a():
    content = ""
    CurrentUser.createEntry("2A", 'AA', 123)

    with open('currentusers.txt', 'r') as file:
        lines = file.readlines()
        for line in lines:
            if line.startswith("2A"):
                content = line[19:28]

    assert content == "123.00000"

    CurrentUser.removeEntry("2A")

def test_createEntry2b():
    content = ""
    CurrentUser.createEntry("2B", 'AA', 123456789123)

    with open('currentusers.txt', 'r') as file:
        lines = file.readlines()
        for line in lines:
            if line.startswith("2B"):
                content = line[19:28]

    assert content == "123456789"

    CurrentUser.removeEntry("2B")

def test_createEntry3S(capfd):
    CurrentUser.createEntry("Justin", 'SS', 0)
    out, err = capfd.readouterr()
    assert out == "ERROR: Type - Constraint, Transaction - create, Description - User already exists in file\n"

def test_createEntry4S():
    content = ""
    CurrentUser.createEntry("4S", 'AA', 100)

    with open('currentusers.txt', 'r') as file:
        lines = file.readlines()
        for line in lines:
                content = line

    assert content == "4S______________AA_100.00000\n"

    CurrentUser.removeEntry("4S")
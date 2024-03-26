from currentusers import CurrentUser
# python3 -m pytest in project folder to run pytests. Must have test_<name of test>.py format to be run as a pytest

def test_readFile5S(capfd):
    CurrentUser.readFile()
    out, err = capfd.readouterr()
    
    filepath = "currentusers.txt"
    expected_output = ""
    with open(filepath, 'r') as file:
        expected_output = file.read()
    
    assert out == expected_output
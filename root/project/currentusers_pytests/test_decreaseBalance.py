from currentusers import CurrentUser
# python3 -m pytest in project folder to run pytests. Must have test_<name of test>.py format to be run as a pytest

def test_decreaseBalance9S(capfd):
    filepath = "currentusers.txt"

    with open(filepath, 'r') as file:
        original_content = file.read()
 
    with open(filepath, 'w') as file:
        file.write("Test_SS_________SS_500.00000")

    CurrentUser.decreaseBalance("Test SS", 500)
    out, err = capfd.readouterr()

    assert out == "Balance for Test SS decreased to 0.0.\n"

    with open(filepath, 'w') as file:
        file.write(original_content)

def test_decreaseBalance9F(capfd):
    CurrentUser.decreaseBalance("Aidan", 10)
    out, err = capfd.readouterr()
    assert out == "ERROR: Type - Constraint, Transaction - buy/refund, Description - User does not exist in file\n"

def test_decreaseBalance10(capfd):
    CurrentUser.decreaseBalance("Justin", 10)
    out, err = capfd.readouterr()
    assert out == "ERROR: Type - Constraint, Transaction - buy/refund, Description - User will have negative balance\n"


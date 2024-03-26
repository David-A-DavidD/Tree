from currentusers import CurrentUser
# python3 -m pytest in project folder to run pytests. Must have test_<name of test>.py format to be run as a pytest

def test_decreaseBalance9S(capfd):
    CurrentUser.decreaseBalance("Test SS", 500)
    out, err = capfd.readouterr()

    assert out == "Balance for Test SS decreased to 0.0.\n"

    CurrentUser.increaseBalance("Test SS", 500)

def test_decreaseBalance9F(capfd):
    CurrentUser.decreaseBalance("Aidan", 10)
    out, err = capfd.readouterr()
    assert out == "ERROR: Type - Constraint, Transaction - buy/refund, Description - User does not exist in file\n"

def test_decreaseBalance10(capfd):
    CurrentUser.decreaseBalance("Justin", 10)
    out, err = capfd.readouterr()
    assert out == "ERROR: Type - Constraint, Transaction - buy/refund, Description - User will have negative balance\n"


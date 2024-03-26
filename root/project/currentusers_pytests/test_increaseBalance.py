from currentusers import CurrentUser
# python3 -m pytest in project folder to run pytests. Must have test_<name of test>.py format to be run as a pytest

def test_increaseBalance7S(capfd):
    CurrentUser.increaseBalance("Justin", 500)
    out, err = capfd.readouterr()

    assert out == "Balance for Justin increased to 500.0.\n"

    CurrentUser.decreaseBalance("Justin", 500)

def test_increaseBalance7F(capfd):
    CurrentUser.increaseBalance("Aidan", 10)
    out, err = capfd.readouterr()
    assert out == "ERROR: Type - Constraint, Transaction - refund/addcredit/buy, Description - User does not exist in file\n"


from currentusers import CurrentUser
# python3 -m pytest in project folder to run pytests. Must have test_<name of test>.py format to be run as a pytest

def test_increaseBalance7S(capfd):
    filepath = "currentusers.txt"

    with open(filepath, 'r') as file:
        original_content = file.read()
 
    with open(filepath, 'w') as file:
        file.write("Justin__________AA_0.0000000")

    CurrentUser.increaseBalance("Justin", 500)
    out, err = capfd.readouterr()

    assert out == "Balance for Justin increased to 500.0.\n"

    with open(filepath, 'w') as file:
        file.write(original_content)

def test_increaseBalance7F(capfd):
    CurrentUser.increaseBalance("Aidan", 10)
    out, err = capfd.readouterr()
    assert out == "ERROR: Type - Constraint, Transaction - refund/addcredit/buy, Description - User does not exist in file\n"


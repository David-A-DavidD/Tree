from dailytransaction import DailyTransaction

def test_clearEntries(capfd):

    filepath = "./dailytransaction_files/dailytransactions.txt"

    with open(filepath, 'r') as file:
        original_content = file.read()

    DailyTransaction.clearEntries()
    out, err = capfd.readouterr()

    assert out == "DTF file successfully cleared.\n"

    with open(filepath, 'w') as file:
        file.write(original_content)
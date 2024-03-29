from dailytransaction import DailyTransaction

def test_mergeDTF(capfd):

    filepath = "./dailytransaction_files/dailytransactions_merged.txt"

    with open(filepath, 'r') as file:
        original_content = file.read()

    DailyTransaction.mergeDTF()
    out, err = capfd.readouterr()

    assert out == "All DTF files successfully merged.\n"

    with open(filepath, 'w') as file:
        file.write(original_content)
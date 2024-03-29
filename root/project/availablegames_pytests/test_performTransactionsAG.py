from availablegames import AvailableGames
# python3 -m pytest in project folder to run pytests. Must have test_<name of test>.py format to be run as a pytest

#TODO fix the file.write and change filepathusers to games


def test_performTransactions15(capfd):
    filepath = "dailytransaction_files/dailytransactions.txt"
    with open(filepath, 'r') as file:
        original_content = file.read()
 
    with open(filepath, 'w') as file:
       file.write("01_Test_Game_____Test_Seller_10.00\n")
   
    available_games = AvailableGames(filepath)  # Instantiate AvailableGames
    available_games.performTransactions()  # Call performTransactions method

    #vailableGames.performTransactions()
    out, err = capfd.readouterr()

    assert out == "Reading line 01_Test_Game_____Test_Seller_10.00\n"

    with open(filepath, 'w') as file:
        file.write(original_content)

def test_performTransactions16(capfd):
    filepath = "dailytransaction_files/dailytransactions.txt"
    with open(filepath, 'r') as file:
        original_content = file.read()
 
    with open(filepath, 'w') as file:
        file.write("02_Test_Game_____Test_Seller_10.00\n")
    available_games = AvailableGames(filepath)  # Instantiate AvailableGames
    available_games.performTransactions()  # Call performTransactions method

   # AvailableGames.performTransactions()
    out, err = capfd.readouterr()

    assert out == "Reading line 02_Test_Game_____Test_Seller_10.00\n"

    with open(filepath, 'w') as file:
        file.write(original_content)

def test_performTransactions17(capfd):
    filepath = "dailytransaction_files/dailytransactions.txt"
    filepath_users = "availablegames.txt"

    with open(filepath_users, 'r') as file:
        original_content_users = file.read()

    with open(filepath, 'r') as file:
        original_content = file.read()
 
    with open(filepath, 'w') as file:
        file.write("04_Mortal_Kombat_______Test_SS_________Justin_________100.00")

    with open(filepath_users, 'w') as file:
        file.write("Justin__________AA_100.00000\nTest_SS_________SS_500.00000\n")

    available_games = AvailableGames(filepath)  # Instantiate AvailableGames
    available_games.performTransactions()  # Call performTransactions method

    #AvailableGames.performTransactions()
    out, err = capfd.readouterr()

    assert out == "Reading line 04_Mortal_Kombat_______Test_SS_________Justin_________100.00\nBalance for Test SS increased to 600.0.\nBalance for Justin decreased to 0.0.\n"

    with open(filepath, 'w') as file:
        file.write(original_content)
    
    with open(filepath_users, 'w') as file:
        file.write(original_content_users)

def test_performTransactions18(capfd):
    filepath = "dailytransaction_files/dailytransactions.txt"
    filepath_users = "availablegames.txt"

    with open(filepath_users, 'r') as file:
        original_content_users = file.read()

    with open(filepath, 'r') as file:
        original_content = file.read()
 
    with open(filepath, 'w') as file:
        file.write("05_Justin__________Test_SS_________100.00000")
    
    with open(filepath_users, 'w') as file:
        file.write("Justin__________AA_0.0000000\nTest_SS_________SS_500.00000\n")

    available_games = AvailableGames(filepath)  # Instantiate AvailableGames
    available_games.performTransactions()  # Call performTransactions method
    
    #AvailableGames.performTransactions()
    out, err = capfd.readouterr()

    assert out == "Reading line 05_Justin__________Test_SS_________100.00000\nBalance for Justin increased to 100.0.\nBalance for Test SS decreased to 400.0.\n"

    with open(filepath, 'w') as file:
        file.write(original_content)
    
    with open(filepath_users, 'w') as file:
        file.write(original_content_users)
        
def test_performTransactions19(capfd):
    filepath = "dailytransaction_files/dailytransactions.txt"
    filepath_users = "availablegames.txt"

    with open(filepath_users, 'r') as file:
        original_content_users = file.read()

    with open(filepath, 'r') as file:
        original_content = file.read()
 
    with open(filepath, 'w') as file:
        file.write("06_Justin__________AA_500.00000")
    
    with open(filepath_users, 'w') as file:
        file.write("Justin__________AA_0.0000000\n")

    available_games = AvailableGames(filepath)  # Instantiate AvailableGames
    available_games.performTransactions()  # Call performTransactions method
    
    #AvailableGames.performTransactions()
    out, err = capfd.readouterr()

    assert out == "Reading line 06_Justin__________AA_500.00000\nBalance for Justin increased to 500.0.\n"

    with open(filepath, 'w') as file:
        file.write(original_content)
    
    with open(filepath_users, 'w') as file:
        file.write(original_content_users)

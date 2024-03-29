#This file will carry out path coverage tests for the createEntry method in availablegames.py

#import pytest, uncomment if needed
from availablegames import AvailableGames
# Define the file path
file_path = "availablegames.txt"

#TC1, write entry with truncated name & price 
def testCase1():
    # Create an instance of AvailableGames with existing file
    availablegames = AvailableGames(file_path)

    # Write an entry with truncated name and price
    availablegames.createEntry("Truncated Name1", "Seller1", 10.123456789)

    # Verify that the entry is correctly written to the file
    with open(file_path, 'r') as file:
        #content = file.read() IS THIS CAUSING ISSUE?
        #assert "Truncated Nam_Seller1_10.12" in content IS THIS CAUSING ISSUE?
        lines = file.readlines()
        found = any("Truncated Nam_Seller1_10.12".replace(" ", "") in line.replace(" ", "") for line in lines)
        assert found, "Entry not found in file."
        #assert any("Truncated Nam_Seller1_10.12" in line for line in lines), "Entry not found in file."
        # Normalize whitespace and check for the entry
        #assert any("Truncated Nam_Seller1_10.12".replace(" ", "") in line.replace(" ", "") for line in lines), "Entry not found in file."
        #for line in lines:
           # print("Line from file:", repr(line))  # Print each line in a format that shows whitespace characters
        # Normalize whitespace and check for the entry
       # assert any("Truncated Nam_Seller1_10.12".replace(" ", "") in line.replace(" ", "") for line in lines), "Entry not found in file."

#TC2, write entry with truncated price 
def testCase2():
    # Create an instance of AvailableGames with existing file
    availablegames = AvailableGames(file_path)

    # Write an entry with truncated price
    availablegames.createEntry("Name", "Seller", 15.6789)

    # Verify that the entry is correctly written to the file
    with open(file_path, 'r') as file:
        content = file.read()
        assert "Name_Seller_15.67" in content

#TC3, write entry with truncated name
def testCase3():
    # Create an instance of AvailableGames with existing file
    available_games = AvailableGames(file_path)

    # Write an entry with truncated name
    available_games.createEntry("Truncated Name2", "Seller", 20.0)

    # Verify that the entry is correctly written to the file
    with open(file_path, 'r') as file:
        content = file.read()
        assert "Truncated Nam_Seller_20.00" in content


#TC4, write entry with no truncation for name and price 
def testCase4():
    # Create an instance of AvailableGames with existing file
    available_games = AvailableGames(file_path)
    
    # Write an entry with no truncation for name and price
    available_games.createEntry("Full Name3", "Seller", 30.50)

    # Verify that the entry is correctly written to the file
    with open(file_path, 'r') as file:
        content = file.read()
        assert "Full Name3_Seller_30.50" in content

#TC5, truncate name & price but game is already in file. dont write to file 
def testCase5():
    # Create an instance of AvailableGames with existing file
    available_games = AvailableGames(file_path)
    
    # Write an entry with truncated name and price, but game is already in the file
    available_games.createEntry("modern_warfare", "michael", 80.000)

    # Verify that the entry is not written to the file again
    with open(file_path, 'r') as file:
        content = file.read()
        assert "modern_war_____________michael_________80.0" not in content #truncated name and price, confirm written correctly.

#TC6, truncate name but game is already in file, dont write to file
def testCase6():
    # Create an instance of AvailableGames with existing file
    available_games = AvailableGames(file_path)
    
    # Write an entry with truncated name, but game is already in the file
    available_games.createEntry("Truncated Name", "Seller", 40.25)

    # Verify that the entry is not written to the file again
    with open(file_path, 'r') as file:
        content = file.read()
        assert "Truncated Name_Seller_40.25" not in content

#TC7, Truncate price but game is already in file. dont write to file 
def testCase7():
    # Create an instance of AvailableGames with existing file
    available_games = AvailableGames(file_path)
    
    # Write an entry with truncated price, but game is already in the file
    available_games.createEntry("Name", "Seller", 18.123456789)

    # Verify that the entry is not written to the file again
    with open(file_path, 'r') as file:
        content = file.read()
        assert "Name_Seller_18.12" not in content


#TC8, dont truncate name and price, but game is already in file. dont write to file.
def testCase8():
# Create an instance of AvailableGames with existing file
    available_games = AvailableGames(file_path)
    
    # Write an entry without truncation for name and price, but game is already in the file
    available_games.createEntry("Full Name", "Seller", 30.50)

    # Verify that the entry is not written to the file again
    with open(file_path, 'r') as file:
        content = file.read()
        assert "Full Name_Seller_30.50" not in content
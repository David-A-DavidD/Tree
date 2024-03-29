import os
import errorLog

#This file represents all interactions between the daily transaction file and the 
#current users file. This file will read the DTF and perform any relevant transactions
#that would occur to the current users file (namely refund, addcredit, create, and delete).
#This file also utilizes the errorLog.py file to log any potential errors that can occur.

# * Note: cd into project folder before running *

class CurrentUser:
    #Constructor
    def __init__(self, username, usertype, credit):
        self.username = username
        self.usertype = usertype
        self.credit = credit

    #This method is used to write an entry into currentusers.txt. This is meant to be called when a 'create' transaction is read from the DTF
    def createEntry(username, usertype, credit): #Parameters for the username, their access type, and credit value
        #Formatting the .txt file for each user
        nameSect = "UUUUUUUUUUUUUUU" 
        creditSect = "CCCCCCCCC"

        #Replace spaces in username with underscores
        username = username.replace(' ', '_')

        #Fill in name section according to username length
        lenNameSect = len(nameSect)
        if len(username) > lenNameSect:
            username = username[:lenNameSect]
        elif len(username) < lenNameSect:
            username += '_' * (lenNameSect - len(username))

        #Fill in credit section according to credit length
        lenCreditSect = len(creditSect)
        creditString = "{:.2f}".format(credit) 

        #Checking if credit goes over character limit, or is too short
        if len(creditString) > lenCreditSect:
            creditString = creditString[:lenCreditSect]
        elif len(creditString) < lenCreditSect:
            creditString += '0' * (lenCreditSect - len(creditString))

        #Checking if username already exists in the file (reading through the file)
        filepath = "currentusers.txt"
 
        with open(filepath, 'r') as inputFile:
            lines = inputFile.readlines()
            for line in lines:
                if line.startswith(username):
                    errorLog.logConstraint("Constraint", "create", "User already exists in file")
                    return

        #Prepare the user entry into the file
        entry = f"{username}_{usertype}_{creditString}\n"

        #Append the entry into the currentusers.txt file
        with open(filepath, 'a') as outputFile:
            outputFile.write(entry)
            print("Account Created!")

    #This method is used to create an END user that will appear at the bottom of the .txt file, signaling the end of the file
    def createEndUser():
        CurrentUser.createEntry("END","  ",0)

    #This method is used to read the contents of the .txt file and print them to the terminal
    def readFile():
        filepath = "currentusers.txt"
       
        with open(filepath, 'r') as inputFile:
            lines = inputFile.readlines()
            for line in lines:
                print(f"{line.strip()}")


    #This method is used to increase the credit of the provided username in the file. This is meant to be called when an 'addcredit', sale from a 'buy' or 'refund' transaction is read from the DTF
    def increaseBalance(username, credit):
        filepath = "currentusers.txt"
        originalUsername = username #Store original username prior to formatting (for console outputs)
        originalUsername = originalUsername.replace('_', ' ')
        originalUsername = originalUsername.rstrip()
        username = username.replace(' ', '_') #Replace any spaces in the username with underscores to fit file structure
        with open(filepath, 'r+') as inputFile: #Open with RW privileges
            lines = inputFile.readlines()

            #This will iterate through the entries of the file until it finds the line that matches the username whose balance needs to be increased.
            #It will then split the entry into its individual parts and add the specified credit accordingly
            for i, line in enumerate(lines):
                if line.startswith(username):
                    parts = line.split('_')
                    current_credit = float(parts[-1])
                    new_credit = current_credit + credit
                    parts[-1] = "{:.2f}".format(new_credit).ljust(9,'0')
                    lines[i] = '_'.join(parts) + "\n"
                    inputFile.seek(0)
                    inputFile.writelines(lines)
                    inputFile.truncate()
                    print(f"Balance for {originalUsername} increased to {new_credit}.")
                    return
            else:
                errorLog.logConstraint("Constraint", "refund/addcredit/buy", "User does not exist in file")

    #This method is used to decrease the credit of the provided username in the file. This is meant to be called when a 'buy' transaction is read from the DTF
    def decreaseBalance(username, credit):
        filepath = "currentusers.txt"
        originalUsername = username #Store original username prior to formatting (for console outputs)
        originalUsername = originalUsername.replace('_', ' ')
        originalUsername = originalUsername.rstrip()
        username = username.replace(' ', '_') #Replace any spaces in the username with underscores to fit file structure
        with open(filepath, 'r+') as inputFile: #Open with RW privileges
            lines = inputFile.readlines()

            #This will iterate through the entries of the file until it finds the line that matches the username whose balance needs to be decreased.
            #It will then split the entry into its individual parts and lower the specified credit accordingly
            for i, line in enumerate(lines):
                if line.startswith(username):
                    parts = line.split('_')
                    currentCredit = float(parts[-1])
                    newCredit = currentCredit - credit

                    if (newCredit >= 0):
                        parts[-1] = "{:.2f}".format(newCredit).ljust(9,'0')
                        lines[i] = '_'.join(parts) + "\n"
                        inputFile.seek(0)
                        inputFile.writelines(lines)
                        inputFile.truncate()
                        print(f"Balance for {originalUsername} decreased to {newCredit}.")
                        return
                    else:
                        errorLog.logConstraint("Constraint", "buy/refund", "User will have negative balance")
                        return
            else:
                errorLog.logConstraint("Constraint", "buy/refund", "User does not exist in file")
    
    #This method is used to remove an existing entry from the current users file. This is meant to be called when a 'delete' transaction is read from the DTF
    def removeEntry(username):
        filepath = "currentusers.txt"
        originalUsername = username #Store original username prior to formatting (for console outputs)
        originalUsername = originalUsername.replace('_', ' ')
        originalUsername = originalUsername.rstrip()
        username = username.replace(' ', '_') #Replace any spaces in the username with underscores to fit file structure

        with open(filepath, 'r+') as inputFile: #Open with RW privileges
            lines = inputFile.readlines()
            inputFile.seek(0)
            inputFile.truncate()

            #Using a flag, the method is essentially rewriting the file contents without the entry of the user being removed.
            isRemoved = False  
            for line in lines:
                if not line.startswith(username):
                    inputFile.write(line)
                else:
                    isRemoved = True
            if isRemoved:
                print(f"{originalUsername} removed.")
            else:
                errorLog.logConstraint("Constraint", "delete", "User does not exist in file")
        
        return isRemoved

    
    def performTransactions():
        filepath = "dailytransaction_files/dailytransactions.txt"

        with open(filepath, 'r') as file:
            lines = file.readlines()  # Read all lines

        # Iterate over each line
        for line in lines:
            # Split the line based on underscore ('_')
            parts = line.strip().split('_')

            # Extract relevant information
            transactionCode = parts[0]  # Transaction type

            if (transactionCode == '01'): #create commmand
                print(f"Reading line {line}")
                username = line[3:18]
                usertype = line[19:21]
                credit = float(parts[-1])
                CurrentUser.createEntry(username, usertype, credit) 
            elif (transactionCode == '02'): #delete command
                print(f"Reading line {line}")
                username = line[3:18]
                CurrentUser.removeEntry(username)
            elif (transactionCode == '04'): #buy command
                print(f"Reading line {line}")
                seller = line[23:38]
                buyer = line[39:53]
                credit = float(parts[-1])
                CurrentUser.increaseBalance(seller, credit)
                CurrentUser.decreaseBalance(buyer, credit)
            elif (transactionCode == '05'): #refund command
                print(f"Reading line {line}")
                buyer = line[3:18]
                seller = line[19:34]
                credit = float(parts[-1])
                CurrentUser.increaseBalance(buyer, credit)
                CurrentUser.decreaseBalance(seller, credit)
            elif (transactionCode == '06'): #addcredit command
                print(f"Reading line {line}")
                username = line[3:18]
                credit = float(parts[-1])
                CurrentUser.increaseBalance(username, credit)
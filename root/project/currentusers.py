import os
import errorLog

#This file represents all interactions between the daily transaction file and the 
#current users file. This file will read the DTF and perform any relevant transactions
#that would occur to the current users file (namely refund, addcredit, create, and delete).
#This file also utilizes the errorLog.py file to log any potential errors that can occur.

#TODO
# - Read from DTF and apply methods to currentusers.txt accordingly

# * Note: cd into project folder before running *

class CurrentUser:
    #Constructor
    def __init__(self, username, usertype, credit):
        self.username = username
        self.usertype = usertype
        self.credit = credit

    #This method is used to write an entry into currentusers.txt. This is meant to be called when a 'create' transaction is read from the DTF
    def createEntry(username, user_type, credit): #Parameters for the username, their access type, and credit value

        #Formatting the .txt file for each user
        name_sect = "UUUUUUUUUUUUUUU" 
        credit_sect = "CCCCCCCCC"

        #Replace spaces in username with underscores
        username = username.replace(' ', '_')

        #Fill in name section according to username length
        len_name_sect = len(name_sect)
        if len(username) > len_name_sect:
            username = username[:len_name_sect]
        elif len(username) < len_name_sect:
            username += '_' * (len_name_sect - len(username))

        #Fill in credit section according to credit length
        len_credit_sect = len(credit_sect)
        credit_string = "{:.2f}".format(credit) 

        #Checking if credit goes over character limit, or is too short
        if len(credit_string) > len_credit_sect:
            credit_string = credit_string[:len_credit_sect]
        elif len(credit_string) < len_credit_sect:
            credit_string += '0' * (len_credit_sect - len(credit_string))

        #Checking if username already exists in the file (reading through the file)
        file_path = "currentusers.txt"
        if os.path.exists(file_path):
            try:
                with open(file_path, 'r') as inputFile:
                    lines = inputFile.readlines()
                    for line in lines:
                        if line.startswith(username):
                            errorLog.logConstraint("Constraint", "create", "User already exists in file")
                            return
            except IOError:
                errorLog.logFatal("Fatal", file_path, "Cannot open file for reading")

        #Prepare the user entry into the file
        entry = f"{username}_{user_type}_{credit_string}\n"

        #Append the entry into the currentusers.txt file
        try:
            with open(file_path, 'a') as outputFile:
                outputFile.write(entry)
        except IOError:
            errorLog.logFatal("Fatal", file_path, "Cannot open file for writing")

    #This method is used to create an END user that will appear at the bottom of the .txt file, signaling the end of the file
    def createEndUser():
        CurrentUser.createEntry("END","  ",0)

    #This method is used to read the contents of the .txt file and print them to the terminal
    def readFile():
        file_path = "currentusers.txt"
        if os.path.exists(file_path):
            try:
                with open(file_path, 'r') as inputFile:
                    lines = inputFile.readlines()
                    for line in lines:
                        print(f"{line.strip()}")
            except IOError:
                errorLog.logFatal("Fatal", file_path, "Cannot open file for reading")
        else:
            errorLog.logFatal("Fatal", file_path, "File does not exist")

    #This method is used to increase the credit of the provided username in the file. This is meant to be called when an 'addcredit' or 'refund' transaction is read from the DTF
    def increaseBalance(username, credit):
        file_path = "currentusers.txt"
        username = username.replace(' ', '_') #Replace any spaces in the username with underscores to fit file structure
        if os.path.exists(file_path):
            try:
                with open(file_path, 'r+') as inputFile: #Open with RW privileges
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
                            print(f"Balance for {username} increased to {new_credit}.")
                            return
                    else:
                        errorLog.logConstraint("Constraint", "refund/addcredit", "User does not exist in file")
            except IOError:
                errorLog.logFatal("Fatal", file_path, "Cannot open file for reading/writing")
        else:
            errorLog.logFatal("Fatal", file_path, "File does not exist")

    #This method is used to decrease the credit of the provided username in the file. This is meant to be called when a 'refund' transaction is read from the DTF
    def decreaseBalance(username, credit):
        file_path = "currentusers.txt"
        username = username.replace(' ', '_') #Replace any spaces in the username with underscores to fit file structure
        if os.path.exists(file_path):
            try:
                with open(file_path, 'r+') as inputFile: #Open with RW privileges
                    lines = inputFile.readlines()

                    #This will iterate through the entries of the file until it finds the line that matches the username whose balance needs to be decreased.
                    #It will then split the entry into its individual parts and lower the specified credit accordingly
                    for i, line in enumerate(lines):
                        if line.startswith(username):
                            parts = line.split('_')
                            current_credit = float(parts[-1])
                            new_credit = current_credit - credit

                            if (new_credit >= 0):
                                parts[-1] = "{:.2f}".format(new_credit).ljust(9,'0')
                                lines[i] = '_'.join(parts) + "\n"
                                inputFile.seek(0)
                                inputFile.writelines(lines)
                                inputFile.truncate()
                                print(f"Balance for {username} decreased to {new_credit}.")
                                return
                            else:
                                errorLog.logConstraint("Constraint", "refund", "User will have negative balance")
                                return
                    else:
                        errorLog.logConstraint("Constraint", "refund", "User does not exist in file")
            except IOError:
                errorLog.logFatal("Fatal", file_path, "Cannot open file for reading/writing")
        else:
            errorLog.logFatal("Fatal", file_path, "File does not exist")
    
    #This method is used to remove an existing entry from the current users file. This is meant to be called when a 'delete' transaction is read from the DTF
    def removeEntry(username):
        file_path = "currentusers.txt"
        originalUsername = username #Store original username prior to formatting (for console outputs)
        username = username.replace(' ', '_') #Replace any spaces in the username with underscores to fit file structure
        if os.path.exists(file_path):
            try:
                with open(file_path, 'r+') as inputFile: #Open with RW privileges
                    lines = inputFile.readlines()
                    inputFile.seek(0)
                    inputFile.truncate()

                    #Using a flag, the method is essentially rewriting the file contents without the entry of the user being removed.
                    entry_removed = False  
                    for line in lines:
                        if not line.startswith(username):
                            inputFile.write(line)
                        else:
                            entry_removed = True
                    if entry_removed:
                        print(f"{originalUsername} removed.")
                    else:
                        errorLog.logConstraint("Constraint", "delete", "User does not exist in file")
            except IOError:
                errorLog.logFatal("Fatal", file_path, "Cannot open file for reading/writing")
        else:
            errorLog.logFatal("Fatal", file_path, "File does not exist")

#Main method for testing purposes
if __name__ == "__main__":
    #CurrentUser.createEntry("Justin", 'AA', 0)
    #CurrentUser.createEntry("Test FS", 'FS', 0)
    #CurrentUser.createEntry("Test BS", 'BS', 0)
    #CurrentUser.createEntry("Test SS", 'SS', 0)
    #CurrentUser.removeEntry("Justin")
    CurrentUser.readFile()

    #CurrentUser.decreaseBalance("Justin", 1000)

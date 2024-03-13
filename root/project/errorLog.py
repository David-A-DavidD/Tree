#This file is solely meant to provide a clean way to produce error messages should they occur within the backend of the system
#Fatal/Constraint errors that may occur can be logged using these methods

#Method to log a constraint error (such as from a transaction being read from the DTF)
def logConstraint(type, transaction, description):
    print(f"ERROR: Type - {type}, Transaction - {transaction}, Description - {description}")

#Method to log a fatal error (such as from an incorrect filename/file contents)
def logFatal(type, filename, description):
    print(f"ERROR: Type - {type}, File - {filename}, Description - {description}")
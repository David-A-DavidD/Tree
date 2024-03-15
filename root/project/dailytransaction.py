import os 

# This file merges all Daily Transaction Files together and performs specific actions related to 
# the dtf files produced for each session

# must be run from project directory

def recordBuyerUsername():
    buyerUserName = "placeholder"
    return buyerUserName

def recordSellerUsername():
    sellerUserName = "placeholder"
    return sellerUserName

# Wipe the DTF
def clear_entries():
    with open("dailytransactions.txt", "w"):
        pass

# Merge all daily transaction files produced for that day
def mergeDTF():
    with open("./transaction_files/transactions_merged.txt", 'w') as out_file:
        for file in os.listdir("./transaction_files"):
            if file.endswith('.txt'):
                file_path = os.path.join("./transaction_files", file)
                with open(file_path, 'r') as in_file:
                    # Read the contents of the file and write to merged transaction file
                    out_file.write(in_file.read())
                    out_file.write('\n')  # Add a newline after each file's content






import os 

# This file manages the backend for Daily Transaction Files

# Must be run from project directory

# Clear all entries from DTF
def clearEntries():
    try: 
        with open("dailytransactions.txt", "w"):
            pass
    except IOError as e:
        print("Could not open dailytransactions.txt", e)

# Merge all daily transaction files produced for that day
def mergeDTF():
    try:
        with open("./dailytransaction_files/dailytransactions_merged.txt", 'w') as out_file:
            for file in os.listdir("./dailytransaction_files"):
                if file.endswith('.txt') and file != "dailytransactions_merged.txt":
                    file_path = os.path.join("./dailytransaction_files", file)
                    with open(file_path, 'r') as in_file:
                        # Read the contents of the dtf file and write to merged dtf file
                        out_file.write(in_file.read())
                        out_file.write('\n')  # Add a newline after each file's content    
    except IOError as e:
        print(f"Could not open 'dailytransactions_merged.txt': {e}")






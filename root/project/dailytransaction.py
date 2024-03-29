import os

# This file manages the backend for Daily Transaction Files

# Must be run from project directory

class DailyTransaction: 

    # Clear all entries from DTF
    def clearEntries():
        with open("dailytransactions.txt", "w"):
            pass
            print("DTF file successfully cleared.")


    # Merge all daily transaction files produced for that day
    def mergeDTF():
        with open("./dailytransaction_files/dailytransactions_merged.txt", 'w') as out_file:
            for file in os.listdir("./dailytransaction_files"):
                if file.endswith('.txt') and file != "dailytransactions_merged.txt":
                    file_path = os.path.join("./dailytransaction_files", file)
                    with open(file_path, 'r') as in_file:
                        # Read the contents of the dtf file and write to merged dtf file
                        out_file.write(in_file.read())
                        out_file.write('\n')  # Add a newline after each file's content
                        print("DTF file added to dailytransactions_merged.txt.")






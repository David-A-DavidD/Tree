#!/bin/sh

# This script must be run from Tree/root/scripts directory, where this script resides

cd ../project

g++ main.cpp user.cpp currentusers.cpp availablegames.cpp dailytransaction.cpp admin.cpp -o main

cd ../test_cases 
for transaction in */; do #loop through transactions
    cd "$transaction"
    for testcase in * ; do
        cd "$testcase"
        # pwd
        input_file=$(ls | head -n 1)
        echo "$input_file"
        # while IFS= read -r line; do
        #     echo "$line" | ../../../project/user
        # done < "$input_file" > output.txt
        ../../../project/main < "$input_file" > output.txt
        cd ..
    done
    cd ..
done

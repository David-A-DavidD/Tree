# Compile 
g++ ../../project/main.cpp ../../project/user.cpp ../../project/currentusers.cpp ../../project/availablegames.cpp ../../project/dailytransaction.cpp  ../../project/admin.cpp -o ../../project/main

# Check if compilation was successful
if [ $? -eq 0 ]; then

    # Run the program with input file and save output to a file
    ../../project/main < "../../test_cases/login/TCLI10-Invalid Transaction Completed Test/TC10.in.txt" > "../../scripts/logout/outputTCLI10.txt"
    # Check if program execution was successful
    if [ $? -eq 0 ]; then
        echo "Program executed successfully."
        # Compare output with expected output
        diff -q "../../scripts/login/outputTCLI10.txt" "../../test_cases/login/TCLI10-Invalid Transaction Completed Test/TC10.out.txt"
        if [ $? -eq 0 ]; then
            echo "Output matches expected output."
        else
            echo "Output does not match expected output."
        fi
    else
        echo "Program execution failed."
    fi
else
    echo "Compilation failed. Exiting..."
fi
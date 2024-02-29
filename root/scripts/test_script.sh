#!/bin/sh

# This script must be run from Tree/root/scripts directory, where this script resides

cd ../test_cases 
for transaction in * ; do
    cd "$transaction"
    for testcase in * ; do
        cd "$testcase"
        # This is where system is run with specific input

        # Save output and place in output directory to be compared with test case
        
        cd ..
    done
    cd ..
done

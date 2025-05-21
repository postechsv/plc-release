#!/bin/bash

# Define the output CSV file
output_file="output.csv"

# Write the header to the CSV file
echo "filename,#state" > $output_file

# Loop over each *-state.log file in the current directory
for log_file in $(ls -1v *-state.log); do
    # Check if the file contains ').NzNat'
    if grep -q ').NzNat' "$log_file"; then
        # Extract the line containing ').NzNat'
        value_line=$(grep -m -1 ').NzNat' "$log_file")
        if [ -n "$value_line" ]; then
            # Extract the integer value before ').NzNat' from the line
            integer_value=$(echo "$value_line" | grep 'result NzNat:'  | grep -oE '[0-9]+\)\.NzNat' | sed 's/).NzNat.*//g')
            # Append the filename and integer value to the CSV file
            echo "$log_file,$integer_value" >> $output_file
        fi
    fi
done

# Inform the user that the CSV file has been created
echo "CSV file '$output_file' has been created."


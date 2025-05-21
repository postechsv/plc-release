#!/bin/bash

# Define the output CSV file
output_file="output.csv"

# Write the header to the CSV file
echo "filename,time(ms)" > $output_file

# Loop over each .log file in the current directory
for log_file in $(ls -1v *cb2*.log); do
    # Check if the file contains 'No solution.'
    if grep -q 'No solution.' "$log_file"; then
        # Extract the line containing 'ms cpu' after 'No solution.'
        time_line=$(awk '/No solution./ {flag=1; next} flag && /ms cpu/ {print; flag=0}' "$log_file")
        if [ -n "$time_line" ]; then
            # Extract the value before 'ms cpu' from the line
            time_value=$(echo "$time_line" | grep -oE '[0-9]+ms cpu' | sed 's/ms cpu//')
            # Append the filename and time to the CSV file
            echo "$log_file,$time_value" >> $output_file
        fi
    fi
done

# Inform the user that the CSV file has been created
echo "CSV file '$output_file' has been created."


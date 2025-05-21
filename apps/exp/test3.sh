#!/bin/bash

# Define the output CSV file
output_file="time.csv"
output_file2="state.csv"

# Write the header to the CSV file
echo "filename,time(ms)" > $output_file

# Loop over each .log file in the current directory
for log_file in $(ls -1v *.log); do
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


# Define the output CSV file
output_file2="state.csv"

# Write the header to the CSV file
echo "filename,#state" > $output_file2

# Loop over each *-state.log file in the current directory
for log_file in $(ls -1v *-state.log); do
    # Check if the file contains ').NzNat'
    if grep -q ').NzNat' "$log_file"; then
        # Extract the line containing ').NzNat'
        value_line=$(grep ').NzNat' "$log_file")
        if [ -n "$value_line" ]; then
            # Extract the integer value before ').NzNat' from the line
            integer_value=$(echo "$value_line" | grep -oE '[0-9]+\)\.NzNat' | sed 's/).NzNat//')
            clean_filename=$(echo "$log_file" | sed 's/-state//')
            # Append the filename and integer value to the CSV file
            echo "$clean_filename,$integer_value" >> $output_file2
        fi
    fi
done

# Define input CSV files and output CSV file
time_csv="time.csv"
state_csv="state.csv"
result_csv="result.csv"

# Check if input files exist
if [[ ! -f "$time_csv" ]] || [[ ! -f "$state_csv" ]]; then
    echo "One or both input files do not exist."
    exit 1
fi

# Join the two CSV files by 'filename' attribute
awk -F, 'NR==FNR {a[$1]=$2; next} $1 in a {print $1","a[$1]","$2}' "$time_csv" "$state_csv" > "$result_csv"

# Inform the user that the result CSV file has been created
echo "CSV file '$result_csv' has been created."

rm $output_file
rm $output_file2

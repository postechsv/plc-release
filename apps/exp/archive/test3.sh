#!/bin/bash

# Define the output CSV file
output_file="time.csv"
output_file2="state.csv"

# Write the header to the CSV file
echo "filename,time(ms)" > $output_file

# Loop over each .log file in the current directory
for log_file in $(ls -1v | egrep '*[a-df-z1-3].log'); do
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
    else
        echo "$log_file,-" >> $output_file
    fi
done


# Define the output CSV file

# Write the header to the CSV file
echo "filename,#state" > $output_file2

# Loop over each *-state.log file in the current directory
for log_file2 in $(ls -1v *-state.log); do
    # Check if the file contains ').NzNat'
    if grep -q ').NzNat' "$log_file2"; then
        # Extract the line containing ').NzNat'
        value_line=$(grep ').NzNat' "$log_file2")
        echo "$log_file2"
        if [ -n "$value_line" ]; then
            # Extract the integer value before ').NzNat' from the line
            integer_value=$(echo "$value_line" | grep 'result NzNat:' | grep -oE '[0-9]+\)\.NzNat' | sed 's/).NzNat//')
            clean_filename=$(echo "$log_file2" | sed 's/-state//')
            # Append the filename and integer value to the CSV file
            echo "$clean_filename,$integer_value" >> $output_file2
        fi
    else
        echo "$clean_filename,-" >> $output_file2
    fi
done

# Define input CSV files and output CSV file
time_csv="time.csv"
state_csv="state.csv"
result_csv="result.csv"

tmp_file=$(mktemp)

# Add headers to the result file
echo "key,value1,value2" > "$tmp_file"

# Use awk to join the files by the first column
awk -F, '
    NR==FNR {
        # Read the first file and store the values in an array
        a[$1] = $2
        next
    }
    {
        # For each line in the second file, check if the key exists in the first file
        key = $1
        value1 = (key in a) ? a[key] : "-"
        value2 = $2
        print key "," value1 "," value2
    }
' "$time_csv" "$state_csv" >> "$tmp_file"

# Add entries from the first file that are not in the second file
awk -F, '
    NR==FNR {
        b[$1] = $2
        next
    }
    {
        if (!($1 in b)) {
            print $1 "," $2 ",-"
        }
    }
' "$state_csv" "$time_csv" >> "$tmp_file"

# Remove duplicate header
awk '!seen[$0]++' "$tmp_file" > "$result_csv"


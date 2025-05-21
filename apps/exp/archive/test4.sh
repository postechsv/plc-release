#!/bin/bash

# Define the input files and output file
file1="time.csv"
file2="state.csv"
output="output.csv"

# Temporary files for processing
temp1="temp1.csv"
temp2="temp2.csv"

# Ensure the first columns are sorted
sort -t, -k1,1 "$file1" -o "$temp1"
sort -t, -k1,1 "$file2" -o "$temp2"

# Determine the number of columns in each file
cols1=$(head -n 1 "$temp1" | awk -F, '{print NF}')
cols2=$(head -n 1 "$temp2" | awk -F, '{print NF}')

# Create a template for missing columns
missing_cols=$(printf ",-"%.0s $(seq $((cols2-1))))

# Prepare the second file by appending missing columns
awk -F, -v OFS=',' -v cols1="$cols1" -v cols2="$cols2" -v missing="$missing_cols" \
'BEGIN { while (cols2 < cols1) { $cols2++ = "-" } } { print $0 }' "$temp2" > "$temp2.mod"

# Join the two CSV files by their first column
join -t , -1 1 -2 1 -o auto "$temp1" "$temp2.mod" > "$output"

# Clean up temporary files
rm "$temp1" "$temp2" "$temp2.mod"

# Print a message indicating the operation is complete
echo "CSV files have been joined and saved to $output"

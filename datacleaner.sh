#!/bin/bash

# Input file containing the original cleaned data
input_file="cleaned_Lund_data.csv"

# Output file for cleaned data without comments
output_file="clean_Lund_data_no_comments.csv"

# Step 1: Remove Header and Metadata
# Initialize a flag to skip lines until the data entries begin
skip=0

# Loop through each line in the input file
while IFS= read -r line; do
    # Check for the line that indicates the start of data entries
    if [[ $line == "Datum;Tid (UTC);Lufttemperatur;Kvalitet;"* ]]; then
        skip=1
        continue
    fi

    # If the data entries have started, process the line
    if [ $skip -eq 1 ]; then
        # Check if the line contains "Y;;" (indicating data entry without comments)
        if [[ $line == *"Y;;"* ]]; then
            # No comments to remove, so append directly to the output file
            echo "$line" >> "$output_file"
        else
            # Use awk to remove comments and append to the output file
            echo "$line" | awk -F ';' '{print $1 ";" $2 ";" $3}' >> "$output_file"
        fi
    fi
done < "$input_file"

echo "Data cleaning complete. Cleaned data without comments saved in $output_file."

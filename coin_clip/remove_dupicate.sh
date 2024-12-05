#!/bin/bash

dir="."

for file in "$dir"/*; do
    if [[ "$file" =~ \.png$ && ! "$file" =~ " 2" ]]; then
        rm "$file"
    fi
done

for file in "$dir"/*; do
    if [[ "$file" =~ " 2" && "$file" =~ \.png$ ]]; then
        new_name=$(echo "$file" | sed 's/ 2//')
        mv "$file" "$new_name"
    fi
done

echo "Files have been renamed"


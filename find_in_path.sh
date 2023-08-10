#!/bin/bash

# Define the _which function
_which() {
    local filename="$1"
    local found="false"

    if [ -e "./$filename" ]; then
        echo "$filename found in current directory."
        found="true"
    fi

    IFS=: read -ra paths <<< "$PATH"

    for path in "${paths[@]}"; do
        if [ -e "$path/$filename" ]; then
            echo "$filename found in: $path"
            found="true"
            break
        fi
    done

    if [ "$found" == "false" ]; then
        echo "Could not find '$filename' in PATH."
    fi
}

# Check if filenames argument is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 filename ..."
    exit 1
fi

# Loop through provided filenames
for filename in "$@"; do
    _which "$filename"
done


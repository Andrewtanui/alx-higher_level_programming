#!/bin/bash

# Get the Python file name from the environment variable
python_script="$PYFILE"

# Check if the file exists
if [ -f "$python_script" ]; then
  # Run the Python script
  python3 "$python_script"
else
  echo "Python file not found: $python_script"
fi


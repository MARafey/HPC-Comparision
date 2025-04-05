#!/bin/bash

# Check requirements
command -v g++ >/dev/null 2>&1 || { echo "g++ is required but not installed. Aborting." >&2; exit 1; }
command -v python3 >/dev/null 2>&1 || { echo "Python 3 is required but not installed. Aborting." >&2; exit 1; }
command -v valgrind >/dev/null 2>&1 || { echo "valgrind is required but not installed. Aborting." >&2; exit 1; }

# Create necessary directories if they don't exist
mkdir -p Files Inputs Results

# Install Python dependencies
pip install pandas numpy

# Clean previous results
rm -f Results/*.csv

# Run benchmarks
python3 run.py

echo "Benchmarking completed. Results are available in the Results directory."

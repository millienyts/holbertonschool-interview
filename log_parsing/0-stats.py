#!/usr/bin/python3
"""
Log Parsing Script

This script reads log entries from stdin line by line and computes metrics:
- Total file size from all log entries
- Count of HTTP status codes (200, 301, 400, 401, 403, 404, 405, 500)

After every 10 lines of input or upon receiving a keyboard interrupt (Ctrl + C),
it prints the following statistics:
- Total file size: the sum of all file sizes from the log entries
- Number of lines per status code: only valid status codes are counted and
  printed in ascending order.

Input format expected for each log entry:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

Example usage:
$ ./0-generator.py | ./0-stats.py
"""

import sys


def print_stats(file_size, status_counts):
    """
    Prints the current statistics including total file size and status code counts.

    Args:
        file_size (int): The total size of all the files processed so far.
        status_counts (dict): A dictionary with the count of each valid status code.
    """
    print(f"File size: {file_size}")
    for code in sorted(status_counts):
        if status_counts[code] > 0:
            print(f"{code}: {status_counts[code]}")


# Initialize variables to store total file size and counts for each status code.
file_size = 0
status_counts = {200: 0, 301: 0, 400: 0,
                 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0

try:
    # Read input lines from stdin one by one
    for line in sys.stdin:
        line_count += 1  # Increment the line count

        # Split the line into parts based on spaces
        parts = line.split()

        # Ensure the line has the correct number of parts (>=7 for valid entries)
        if len(parts) >= 7:
            try:
                # Extract the file size and status code from the log entry
                # File size is the last part of the line
                file_size += int(parts[-1])
                # Status code is the second-to-last part
                status_code = int(parts[-2])

                # Update the count for the status code if it's one of the valid codes
                if status_code in status_counts:
                    status_counts[status_code] += 1
            except ValueError:
                # If there's an error (e.g., non-integer status code or file size),
                # skip that line without raising an exception
                pass

        # Every 10 lines, print the current statistics
        if line_count % 10 == 0:
            print_stats(file_size, status_counts)

except KeyboardInterrupt:
    # On a keyboard interrupt (Ctrl + C), print the current statistics
    print_stats(file_size, status_counts)
    raise  # Re-raise the exception to allow graceful exit

# After reaching the end of input (EOF), print the final statistics
print_stats(file_size, status_counts)

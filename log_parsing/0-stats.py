#!/usr/bin/python3
import sys
"""
This module prints the stats and parses log lines
"""


def print_stats(file_size, status_codes):
    """Print the stats for file size and status codes."""
    print(f"File size: {file_size}")
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")

def main():
    """Main function to process the log lines."""
    file_size = 0
    status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0

    try:
        for line in sys.stdin:
            line_count += 1

            # Extract status code and file size from the line
            try:
                parts = line.split(' ')
                status_code = int(parts[-2])
                size = int(parts[-1])

                # If the status code is valid, update the count
                if status_code in status_codes:
                    status_codes[status_code] += 1
                file_size += size

            except (ValueError, IndexError):
                continue  # Skip lines with invalid format

            # Print stats after every 10 lines
            if line_count % 10 == 0:
                print_stats(file_size, status_codes)

    except KeyboardInterrupt:
        # Catch keyboard interrupt and print stats before exiting
        print_stats(file_size, status_codes)

if __name__ == "__main__":
    main()

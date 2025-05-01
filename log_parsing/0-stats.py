#!/usr/bin/python3
"""
This module prints the stats and parses log lines
"""

import sys


def print_stats(file_size, status_codes):
    """Print the stats for file size and status codes."""
    print(f"File size: {file_size}")
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")


def main():
    """Main function to process the log lines."""
    file_size = 0
    status_codes = {200: 0, 301: 0, 400: 0, 401: 0,
                    403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0

    try:
        for line in sys.stdin:
            line_count += 1

            try:
                parts = line.strip().split()
                size = int(parts[-1])
                file_size += size

                status_code = int(parts[-2])
                if status_code in status_codes:
                    status_codes[status_code] += 1
            except (IndexError, ValueError):
                continue

            if line_count % 10 == 0:
                print_stats(file_size, status_codes)

    except KeyboardInterrupt:
        print_stats(file_size, status_codes)
        raise

    # ✅ At the very end, print remaining stats if not already printed
    if line_count % 10 != 0 or line_count == 0:
        print_stats(file_size, status_codes)


if __name__ == "__main__":
    main()

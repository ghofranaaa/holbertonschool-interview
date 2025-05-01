#!/usr/bin/python3
"""
This module validates if the given data is UTF-8
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.
    
    Parameters:
    - data: List of integers where each integer represents 1 byte.
    
    Returns:
    - True if the data is a valid UTF-8 encoding, otherwise False.
    """
    i = 0
    while i < len(data):
        byte = data[i]
        
        # Check if the byte is within the valid range of a byte (0-255)
        if byte < 0 or byte > 255:
            return False
        
        if (byte >> 7) == 0b0:  # 1-byte character (starts with 0)
            i += 1
        elif (byte >> 5) == 0b110:  # 2-byte character (starts with 110)
            if i + 1 >= len(data) or (data[i + 1] >> 6) != 0b10:
                return False
            i += 2
        elif (byte >> 4) == 0b1110:  # 3-byte character (starts with 1110)
            if i + 2 >= len(data) or (data[i + 1] >> 6) != 0b10 or (data[i + 2] >> 6) != 0b10:
                return False
            i += 3
        elif (byte >> 3) == 0b11110:  # 4-byte character (starts with 11110)
            if i + 3 >= len(data) or (data[i + 1] >> 6) != 0b10 or (data[i + 2] >> 6) != 0b10 or (data[i + 3] >> 6) != 0b10:
                return False
            i += 4
        else:
            return False  # Invalid byte (does not match any valid starting bits)

    return True

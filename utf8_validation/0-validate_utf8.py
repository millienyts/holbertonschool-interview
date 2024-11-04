#!/usr/bin/python3
"""
UTF-8 Validation module
"""

from typing import List


def validUTF8(data: List[int]) -> bool:
    """
    Determines if a given data set represents a valid UTF-8 encoding.
    """
    n_bytes = 0  # Number of continuation bytes expected

    # Masks to check the most significant bits
    mask1 = 1 << 7
    mask2 = 1 << 6

    for num in data:
        mask = 1 << 7

        if n_bytes == 0:
            # Determine the number of leading 1's in the first byte
            while mask & num:
                n_bytes += 1
                mask >>= 1

            # For a 1-byte character
            if n_bytes == 0:
                continue

            # Invalid cases: n_bytes should be 2, 3, or 4
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            # Check if it’s a valid continuation byte
            if not (num & mask1 and not (num & mask2)):
                return False

        n_bytes -= 1

    return n_bytes == 0

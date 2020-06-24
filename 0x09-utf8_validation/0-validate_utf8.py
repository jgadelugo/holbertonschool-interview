#!/usr/bin/python3
"""method that determines if a given data set represents
a valid UTF-8 encoding"""


def validUTF8(data):
    """method that determines if a given data set represents
    a valid UTF-8 encoding

    * A character in UTF-8 can be 1 to 4 bytes long
    * The data set can contain multiple characters
    * The data will be represented by a list of integers

    Return: True if data is valid UTF-8 encoding, else return False
    """
    # check if most significant byte is 1 (num & mask1), reset
    mask1 = 1 << 7
    # to check if second most segnificant byte is 0 not (num & mask2)
    mask2 = 1 << 6

    num_bytes = 0

    for num in data:
        # reset mask to count num_bytes
        mask = 1 << 7
        if num_bytes == 0:
            # check num of bytes in first 8 bytes
            # checks to see how many ones it has before a 0
            while (num & mask):
                num_bytes += 1
                mask = mask >> 1

            if num_bytes == 0:
                continue
            # check utf-8 can be 1 to 4 bytes long
            if num_bytes == 1 or num_bytes == 4:
                return False
        else:
            # check that first two bites are 10xxxxxx if not return False
            if not (num & mask1 and not (num & mask2)):
                return False
        num_bytes -= 1

    # check if UTF-8 is uncomplete
    return num_bytes == 0

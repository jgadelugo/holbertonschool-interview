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
    for d in data:
        if d > 255:
            return False
    return True

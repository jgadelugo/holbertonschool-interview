#!/usr/bin/python3
""" Method that determines if all the boxes can be opened """


def canUnlockAll(boxes):
    """ Determines if all the boxes can be opened"""
    size = len(boxes)
    checker = {}
    index = 0

    for keys in boxes:
        if len(keys) == 0 or index == 0:
            checker[index] = -1  # -1 means box is empty
        for key in keys:
                if key < size and key != index:
                    checker[key] = key
        if len(checker) == size:
            return True
        index += 1
    return False

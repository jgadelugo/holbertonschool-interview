#!/usr/bin/python3
"""Return: integer indicating total amount of rainwater retained"""


def rain(walls):
    """rain
    @walls: list of non-negative integers
    Return: integer indicating total amount of rainwater retained
    """
    left = 0
    l_max = 0
    right = len(walls) - 1
    r_max = 0
    retained = 0
    while (left < right):
        if walls[left] < walls[right]:
            if walls[left] >= l_max:
                l_max = walls[left]
            else:
                retained += l_max - walls[left]
            left += 1
        else:
            if walls[right] >= r_max:
                r_max = walls[right]
            else:
                retained += r_max - walls[right]
            right -= 1
    return retained

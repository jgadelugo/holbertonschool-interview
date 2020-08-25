#!/usr/bin/python3
"""Return: integer indicating total amount of rainwater retained"""

def rain(walls):
    """rain
    @walls: list of non-negative integers
    Return: integer indicating total amount of rainwater retained
    """
    trapped = 0
    first_wall = 0
    for i in walls:
        if first_wall == 0:
            first_wall = i
        elif first_wall < i:
            first_wall = i
        else:
            trapped += first_wall - i
    return trapped

#!/usr/bin/python3
"""
Calculates the fewest number of operations needed to resut
in n H characters
"""


def minOperations(n):
    """ fewest number of operations to get n number of 'h'"""
    ops = 0
    i = 2
    while i <= n:
        if n % i == 0:
            ops += i
            n /= i
        else:
            i += 1
    return ops

#!/usr/bin/python3
"""
Return the least number of coins need to return the total
"""


def makeChange(coins, total):
    """Return the least number of coins need to return the total
    @coins: list of the coins available
    @total: total to return
    Return: least number of coins needed to get to total
    """
    num_of_coins = 0
    if total <= 0:
        return 0
    for coin in sorted(coins)[::-1]:
        num_of_coins += total // coin
        total = total % coin
    if total != 0:
        return -1
    return num_of_coins

#!/usr/bin/python3
"""
Returns winner of prime game

Prime Game:
    Maria and Ben are playing a game. Given a set of consecutive integers
    starting from 1 up to and including n, take turns choosing a prime
    number from the set and removing that number and its multiples from
    set. The player that cannot make a move loses the game.

    They play x rounds, where n may be different for each round
    Assuming Maria always goes first and both players play optimally,
    determine who the winner of each game is.
"""


def pop_mults(p, mults):
    """
    removes multiples of p in list mults

    Args:
        p: prime number to get multiples
        mults: list of numbers to remove multiples of p
    Returns:
        returns list without multiples
    """
    max_num = sorted(mults)[-1]
    for i in range(1, max_num):
        _pop = i * p
        if _pop > max_num:
            break
        if _pop in mults:
            mults.remove(_pop)
    return mults


def check_prime(a):
    """
    Checks if a number isi prime

    Args:
        a: number to check it its prime
    Return:
        Boolean, True if prime or False if not
    """
    if a == 1:
        return False
    for i in range(2, a):
        if a % i == 0:
            return False
    return True


def find_next_prime(n):
    """
    gets the next highest prime

    Args:
        n: number to start on
    Return:
        next highest prime number

    """
    if check_prime(n):
        return n

    high = n + 1
    while True:
        if check_prime(high):
            return high
        else:
            high += 1


def isWinner(x, nums):
    """
    Returns winner of prime game

    Prime Game:
        Maria and Ben are playing a game. Given a set of consecutive integers
        starting from 1 up to and including n, take turns choosing a prime
        number from the set and removing that number and its multiples from
        set. The player that cannot make a move loses the game.

        They play x rounds, where n may be different for each round
        Assuming Maria always goes first and both players play optimally,
        determine who the winner of each game is.

    Args:
        x: is the number of rounds
        nums: array of n

    Return:
        winner of each game
    """

    score_board = {'Maria': 0, 'Ben': 0}
    if len(nums) < 1 or list(set(nums)) == [0]:
        return None

    for n in nums:
        det = 0
        if x < 1:
            break
        if n == 0:
            continue

        mults = [i for i in range(1, n + 1)]
        # print("Rounds left:", x)
        # print(f"on {n} mults = {mults}")
        p = 1
        while mults != [] and mults != [1]:
            p = find_next_prime(p)
            if p > n:
                break
            det += 1
            mults = pop_mults(p, mults)
            p += 1
        if det % 2 != 0:
            score_board['Maria'] += 1
        else:
            score_board['Ben'] += 1
        # print(score_board)
        x -= 1

    maria = score_board['Maria']
    ben = score_board['Ben']
    if maria == ben:
        return None
    elif maria > ben:
        return "Maria"
    else:
        return "Ben"

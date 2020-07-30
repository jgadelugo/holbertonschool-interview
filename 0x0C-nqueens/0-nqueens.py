#!/usr/bin/python3


if __name__ == "__main__":
    import sys

    argv = sys.argv
    argc = len(argv)

    if argc != 2:
        print('Usage: nqueens N')
        exit(1)

    try:
        N = int(argv[1])
        if N < 4:
            print('N must be at least 4')
            exit(1)
    except ValueError:
        print('N must be a number')
        exit(1)

    positions = []

    def isSafe(positions, row, col):
        # Check this row on left side
        rows = []
        cols = []
        r_diag = []
        l_diag = []

        for pos in positions:
            # rows and columns
            rows.append(pos[0])
            cols.append(pos[1])

            # diagonals
            r_diag.append(pos[0] + pos[1])
            l_diag.append(pos[1] - pos[0])
        if row in rows or col in cols:
            return False

        if row + col in r_diag or col - row in l_diag:
            return False

        return True

    def nQueens(positions, col, arrays=[]):
        """ Recursively place queens
        @arr: array representing queens positions
        @r: queen we are on
        Return: arr
        """
        for i in range(N):
            if isSafe(positions, i, col):
                positions.append([i, col])
                if col == N - 1:
                    arrays.append(positions.copy())
                    del positions[-1]
                else:
                    nQueens(positions, col + 1)

        if len(positions):
            del positions[-1]
        return arrays

    positions = nQueens(positions, 0)

    for pos in positions:
        print(pos)

#!/usr/bin/python3

"""
Script that solves the N queens problem using the Backtracking algorithm.
"""

import sys


def valid_pos(solution, pos):
    """
    Checks if a position is valid for placing a queen.
    A position is invalid if it conflicts with any already placed queen.
    """
    for queen in solution:
        # Check if another queen is in the same column
        if queen[1] == pos[1]:
            return False
        # Check diagonal conflicts
        if (queen[0] + queen[1]) == (pos[0] + pos[1]):
            return False
        if (queen[0] - queen[1]) == (pos[0] - pos[1]):
            return False
    return True


def solve_queens(row, n, solution):
    """
    Recursively tries to place queens on the board and prints valid solutions.
    """
    if row == n:
        print(solution)
    else:
        for col in range(n):
            pos = [row, col]
            if valid_pos(solution, pos):
                solution.append(pos)
                solve_queens(row + 1, n, solution)
                solution.pop()  # Backtrack by removing the last queen


def main(n):
    """
    Main function to solve the N queens problem.
    """
    solution = []
    solve_queens(0, n, solution)


if __name__ == '__main__':
    # Validate the number of arguments
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print('N must be a number')
        sys.exit(1)

    if n < 4:
        print('N must be at least 4')
        sys.exit(1)

    main(n)

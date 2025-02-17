
"""
N Queens: Solves the N Queens problem using backtracking.
"""

import sys


def is_safe(board, row, col, N):
    """Check if a queen can be placed on board[row][col] without conflicts."""
    for i in range(row):
        if board[i] == col or \
           board[i] - i == col - row or \
           board[i] + i == col + row:
            return False
    return True


def solve_nqueens(N, row=0, board=[]):
    """Recursively solves the N Queens problem."""
    if row == N:
        print([[i, board[i]] for i in range(N)])
        return

    for col in range(N):
        if is_safe(board, row, col, N):
            solve_nqueens(N, row + 1, board + [col])


def main():
    """Main entry point for the N Queens solver."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    solve_nqueens(N)


if __name__ == "__main__":
    main()

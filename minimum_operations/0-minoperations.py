#!/usr/bin/python3
"""Module which contains minoperations function"""


def minOperations(n):
    """ Calculates the fewest number of operations needed
           to result in exactly n H characters in the file

           Args:
               n: repetitions of H

           Returns:
               number of operations (Copy & Paste) to reach n Hs
       """
    if n <= 1:
        return 0

    operations = 0
    divisor = 2

    # Factorizing n to determine the operations
    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    return operations

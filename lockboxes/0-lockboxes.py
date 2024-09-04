#!/usr/bin/python3
'''
    0-lockboxes.py

    This module contains the function canUnlockAll(boxes) that
    determines if all the boxes can be opened.
'''


def canUnlockAll(boxes):
    '''
        Determines if all the boxes can be opened.
    '''
    n = len(boxes)
    unlocked = [False] * n
    unlocked[0] = True

    keys = boxes[0]

    while keys:
        key = keys.pop()
        # If key is valid and box not unlocked yet
        if key < n and not unlocked[key]:
            # Unlock box
            unlocked[key] = True
            # Add keys from unlocked box to list
            keys.extend(boxes[key])

    # If all boxes unlocked
    return all(unlocked)

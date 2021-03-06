#!/usr/bin/python3


def canUnlockAll(boxes):
    """You have n number of locked boxes in front of you. Each box is numbered
    sequentially from 0 to n - 1 and each box may contain keys to the other
    boxes. This method that determines if all the boxes can be opened.

    Return True if all boxes can be opened, else return False"""
    list_comparation = []

    for box in range(len(boxes)):
        for key in boxes[box]:
            if key != box and key < len(boxes) and \
               key != 0 and key not in list_comparation:
                list_comparation.append(key)

    return True if len(list_comparation) == (len(boxes) - 1) else False

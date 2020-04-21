#!/usr/bin/python3


def canUnlockAll(boxes):
    """You have n number of locked boxes in front of you. Each box is numbered
    sequentially from 0 to n - 1 and each box may contain keys to the other
    boxes. This method that determines if all the boxes can be opened.

    Return True if all boxes can be opened, else return False"""
    if boxes == [] or boxes == [[]]:
        return True

    list_comparation = [0]
    for box in range(len(boxes)):
        if boxes[box] == [] and box not in list_comparation:
            list_comparation.append(box)
        for key in boxes[box]:
            if key != box and key < len(boxes) and key not in list_comparation:
                list_comparation.append(key)
    # print()
    # print(list_comparation)
    return True if len(list_comparation) == len(boxes) else False

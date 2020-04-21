#!/usr/bin/python3


def canUnlockAll(boxes):
    """You have n number of locked boxes in front of you. Each box is numbered
    sequentially from 0 to n - 1 and each box may contain keys to the other
    boxes. This method that determines if all the boxes can be opened.

    Return True if all boxes can be opened, else return False"""
    if boxes == [] or boxes == [[]]:
        return True

    all_boxes_empty = True

    list_comparation = [0]
    for box in range(len(boxes)):
        for key in boxes[box]:
            all_boxes_empty = False
            if key != box and key not in list_comparation:
                list_comparation.append(key)

    if all_boxes_empty:
        return True
    return True if len(list_comparation) == len(boxes) else False

#!/usr/bin/python3


def canUnlockAll(boxes):

    if not validate_boxes(boxes):
        return False

    index = 0
    check_boxes_queue = boxes[index]
    unlocked_boxes = [index]

    while index_inside_range(check_boxes_queue, index):
        if index_inside_range(boxes, index):
            box_index = check_boxes_queue[index]
            if box_index not in unlocked_boxes:
                box = boxes[box_index]
                for box_key in box:
                    if box_key not in check_boxes_queue:
                        check_boxes_queue.append(box_key)
                unlocked_boxes.append(box_index)
        index += 1

    return True if all_boxes_unlocked(boxes, unlocked_boxes) else False


def validate_boxes(boxes):
    return boxes is not None and boxes != [] and boxes[0] != []


def index_inside_range(list, index):
    return index < len(list)


def all_boxes_unlocked(origin_boxes, unlocked_boxes):
    return len(origin_boxes) == len(unlocked_boxes)

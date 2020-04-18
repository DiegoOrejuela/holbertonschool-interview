#!/usr/bin/python3

def canUnlockAll(boxes):

    if not validate_boxes(boxes):
        return False

    index = 0
    check_boxes_queue = boxes[index]
    unlocked_boxes = [index]

    while there_are_boxes_to_review(check_boxes_queue, index):
        box_index = check_boxes_queue[index]
        if not box_index in unlocked_boxes:
            box = boxes[box_index]
            for box_key in box:
                check_boxes_queue.append(box_key) if not box_key in check_boxes_queue else None
            unlocked_boxes.append(box_index)
        index += 1

    return True if all_boxes_unlocked(boxes, unlocked_boxes) else False


def validate_boxes(boxes):
    return boxes != None and boxes != [] and boxes[0] != []

def there_are_boxes_to_review(list, index):
    return index < len(list)

def all_boxes_unlocked(origin_boxes, unlocked_boxes):
    return len(origin_boxes) == len(unlocked_boxes)

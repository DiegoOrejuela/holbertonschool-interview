#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))

# my cases test
print('### My cases ###')

boxes = [[]]
print(canUnlockAll(boxes)) #>>> True

boxes = [[], [1]]
print(canUnlockAll(boxes)) #>>> False

boxes = [[0], [1]]
print(canUnlockAll(boxes)) #>>> False

boxes = [[1], []]
print(canUnlockAll(boxes)) #>>> True

boxes = [[1], [3], [], [2]]
print(canUnlockAll(boxes)) #>>> True

boxes = [[1], [1], [2]]
print(canUnlockAll(boxes)) #>>> False

boxes = [[],[5],[666],[],[],[1,2,3,4,5]]
print(canUnlockAll(boxes)) #>>> False -> True

boxes = [[], [], [], [], []]
print(canUnlockAll(boxes)) #>>> True

boxes = [[4],[],[],[],[0]]
print(canUnlockAll(boxes)) #>>> True

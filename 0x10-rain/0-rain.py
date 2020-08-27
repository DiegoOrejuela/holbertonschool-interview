#!/usr/bin/python3

"""
Module rain
"""


def rain(walls):
    """
    Given a list of non-negative integers representing walls of width 1,
    calculate how much water will be retained after it rains.
    walls is a list of non-negative integers.
    Return: Integer indicating total amount of rainwater retained.
    """

    if not walls:
        return 0

    if sum(walls) == max(walls) or len(walls) < 3:
        return 0

    previous_wall = 0
    spaces = []
    retained = 0
    mayor = 0

    for idx, wall in enumerate(walls):

        # if there is a previous wall and a new one to evaluate
        if wall != 0 and previous_wall != 0:

            # the current wall is greater than the previous wall
            if wall >= previous_wall:
                retained += (previous_wall * len(spaces)) - sum(spaces)
                spaces = []
                previous_wall = wall
                if mayor <= wall:
                    mayor = 0

            # the current wall is less than the previous wall
            if wall < previous_wall:

                # check if there is a bigger wall in front
                if mayor == 0:
                    mayor = max(walls[idx:])

                    # there are no more walls to check
                    if mayor == 0:
                        retained += (wall * len(spaces)) - sum(spaces)
                        break

                # current wall is greater than or equal to the following walls
                if wall >= mayor:
                    retained += (wall * len(spaces)) - sum(spaces)
                    mayor = 0
                    spaces = []
                    previous_wall = wall

                # later there are walls bigger than the current, save the wall
                if mayor > wall:
                    spaces.append(wall)

        # found the first wall
        if wall != 0 and previous_wall == 0:
            previous_wall = wall

    return retained

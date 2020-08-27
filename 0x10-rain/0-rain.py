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

    previous_wall = 0
    spaces = []
    retained = 0
    mayor = 0

    for idx, wall in enumerate(walls):

        if wall != 0 and previous_wall != 0:

            if wall >= previous_wall:
                retained += (previous_wall * len(spaces)) - sum(spaces)
                spaces = []
                previous_wall = wall

        if wall != 0 and previous_wall == 0:
            previous_wall = wall

        if wall == 0 and previous_wall != 0:
            spaces.append(wall)

    return retained if retained != 0 else 1

#!/usr/bin/python3

"""
Module that contains a function to calculate the perimeter of an island
represented in a grid.
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island represented by 1s in the grid.

    Args:
        grid (list of list of int): 2D grid map where 1
        represents land and 0 water.

    Returns:
        int: The perimeter of the island.
    """
    perimeter = 0

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                # Start with 4 sides
                perimeter += 4

                # Check above
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2  # Shared edge with upper cell

                # Check left
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2  # Shared edge with left cell

    return perimeter

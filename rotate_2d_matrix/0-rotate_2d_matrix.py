#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """
    Rotates a 2D matrix 90 degrees clockwise in place.

    Args:
        matrix (list of lists): The n x n 2D matrix to rotate.

    Returns:
        None: The matrix is modified in place.
    """
    n = len(matrix)

    # Step 1: transpose the matrix
    for i in range(n):
        for j in range(i + 1, n):
            # swap elements across diagonal
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Step 2: reverse each row
    for i in range(n):
        matrix[i].reverse()

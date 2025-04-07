#!/usr/bin/python3
"""Module to determine if all lockboxes can be opened."""


def canUnlockAll(boxes):
    """
    This function checks if all boxes can be opened.
    """
    if not boxes or not isinstance(boxes, list):
        return False

    num_boxes = len(boxes)
    visited = set()
    to_visit = [0]

    while to_visit:
        current = to_visit.pop()
        if current not in visited:
            visited.add(current)
            for key in boxes[current]:
                if isinstance(key, int)
                and 0 <= key < num_boxes
                and key not in visited:
                    to_visit.append(key)

    return len(visited) == num_boxes

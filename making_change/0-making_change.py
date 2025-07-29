#!/usr/bin/python3
"""
This module provides a function to compute the minimum number of coins
required to meet a given total amount.
"""


def makeChange(coins, total):
    """
    Determines the fewest number of coins needed to make up a given total.

    Args:
        coins (list): List of coin denominations (integers > 0).
        total (int): The amount to reach.

    Returns:
        int: Minimum number of coins needed, or -1 if not possible.
    """
    if total <= 0:
        return 0

    dp = [float('inf')] * (total + 1)
    dp[0] = 0  # 0 coins to make total 0

    for coin in coins:
        for i in range(coin, total + 1):
            if dp[i - coin] != float('inf'):
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1

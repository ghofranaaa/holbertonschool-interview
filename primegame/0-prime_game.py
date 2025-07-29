#!/usr/bin/python3
"""
0-prime_game.py
Determines the winner of the Prime Game
"""


def sieve(n):
    """Returns a list of prime counts up to n using the Sieve of Eratosthenes"""
    is_prime = [False, False] + [True] * (n - 1)
    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i*i, n+1, i):
                is_prime[j] = False
    prime_counts = [0] * (n + 1)
    count = 0
    for i in range(len(is_prime)):
        if is_prime[i]:
            count += 1
        prime_counts[i] = count
    return prime_counts

def isWinner(x, nums):
    """
    Determines who wins the most rounds
    Args:
      x (int): number of rounds
      nums (list): list of n values for each round
    Returns:
      str: name of the player with the most wins, or None
    """
    if not nums or x < 1:
        return None

    max_n = max(nums)
    prime_counts = sieve(max_n)

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if prime_counts[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    return None

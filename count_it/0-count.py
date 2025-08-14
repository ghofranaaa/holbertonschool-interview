#!/usr/bin/python3
"""This module counts occurrences of keywords in hot post titles of a
subreddit using the Reddit API."""
import requests
import re


def count_words(subreddit, word_list, after=None, counts=None):
    """
    Recursively queries the Reddit API to count the occurrences of keywords
    in hot post titles of a subreddit.

    Args:
        subreddit (str): Name of the subreddit to query.
        word_list (list): List of keywords to count.
        after (str, optional): Token for pagination. Defaults to None.
        counts (dict, optional): Dictionary storing keyword counts. Defaults to None.

    Prints:
        Sorted keyword counts in descending order of frequency.
    """

    if counts is None:
        counts = {}

    url = f"https://www.reddit.com/r/{subreddit}/hot.json?limit=100"
    if after:
        url += f"&after={after}"

    headers = {'User-Agent': 'Python:count_words:v1.0 (by /u/yourusername)'}
    response = requests.get(url, headers=headers, allow_redirects=False)

    if response.status_code != 200:
        return  # Invalid subreddit or error

    data = response.json().get('data', {})
    posts = data.get('children', [])
    
    for post in posts:
        title = post['data']['title'].lower()
        for word in word_list:
            word_lower = word.lower()
            # Count exact matches using regex
            matches = re.findall(r'\b{}\b'.format(re.escape(word_lower)), title)
            counts[word_lower] = counts.get(word_lower, 0) + len(matches)

    after = data.get('after')
    if after:
        count_words(subreddit, word_list, after, counts)

    # Only print at the top-most recursion
    if after is None:
        # Sort by count desc, then alphabetically
        for word, count in sorted(counts.items(), key=lambda x: (-x[1], x[0])):
            if count > 0:
                print(f"{word}: {count}")

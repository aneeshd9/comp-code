from collections import defaultdict
from typing import Dict


class Solution:
  def longestPalindrome(self, s: str) -> int:
    '''
    Given a string finds the longest palindrome that can be
    constructed from its characters.
    '''
    counts: Dict[str, int] = defaultdict(int)
    for c in s:
      counts[c] += 1

    maxLength: int = 0
    for char in counts.keys():
      maxLength += counts[char] - (counts[char] % 2)
      counts[char] -= counts[char] - (counts[char] % 2)

    for char in counts.keys():
      if counts[char] > 0:
        maxLength += 1
        break

    return maxLength
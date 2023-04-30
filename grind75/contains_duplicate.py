from typing import List, Set


class Solution:
  def containsDuplicate(self, nums: List[int]) -> bool:
    uniques: Set[int] = set()
    for num in nums:
      if num in uniques:
        return True
      else:
        uniques.add(num)
    return False
from typing import List

class Solution:
  def majorityElement(self, nums: List[int]) -> int:
    ans = 0
    maxCount = 0

    for num in nums:
      if maxCount == 0:
        ans = num

      maxCount += 1 if num == ans else -1

    return ans
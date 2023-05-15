from typing import List


class Solution(object):
    def missingNumber(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums) + 1
        for i in range(1, n):
            ans ^= i
        for num in nums:
            ans ^= num
        return ans

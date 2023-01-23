from typing import List

class Solution(object):
    def missingNumber(self, nums: List[int]):
        ans = 0
        for num in nums:
            ans ^= num
        for i in range(len(nums) + 1):
            ans ^= i
        return ans
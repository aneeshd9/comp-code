from typing import List


class Solution(object):
    def moveZeroes(self, nums: List[int]) -> None:
        insert_pos: int = -1
        for i in range(len(nums)):
            if nums[i] != 0 and insert_pos < len(nums) - 1:
                nums[insert_pos + 1] = nums[i]
                insert_pos += 1
        for i in range(insert_pos + 1, len(nums)):
            nums[i] = 0

if __name__ == "__main__":
    nums: List[int] = [0]
    Solution().moveZeroes(nums)
    print(nums)

from typing import List, Optional


class TreeNode:
    def __init__(self,
                 val: int=0,
                 left: Optional["TreeNode"]=None,
                 right: Optional["TreeNode"]=None) -> None:
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if len(nums) == 0:
            return None
        mid = len(nums) // 2
        root = TreeNode()
        root.val = nums[mid]
        root.left = self.sortedArrayToBST(nums[:mid])
        root.right = self.sortedArrayToBST(nums[mid + 1:])
        return root

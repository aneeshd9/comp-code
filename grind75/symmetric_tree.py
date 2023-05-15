from typing import Optional


class TreeNode:
    def __init__(self,
                 val: int=0,
                 left: Optional["TreeNode"]=None,
                 right: Optional["TreeNode"]=None) -> None:
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return root is None or self.isMirror(root.left, root.right)

    def isMirror(self, node1: Optional[TreeNode], node2: Optional[TreeNode]) -> bool:
        if node1 is None and node2 is None:
            return True
        elif node1 is not None or node2 is not None:
            return False
        elif node1.val != node2.val:
            return False
        else:
            return self.isMirror(node1.left, node2.right) and self.isMirror(node1.right, node2.left)

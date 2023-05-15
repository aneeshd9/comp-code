class Solution(object):
    def isPalindrome(self, x: int) -> bool:
        x_str = str(x)
        low = 0
        high = len(x_str) - 1
        while low < high:
            if x_str[low] != x_str[high]:
                return False
            low += 1
            high -= 1
        return True

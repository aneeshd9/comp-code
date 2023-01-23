from typing import List

class Solution(object):
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ans = []
        l, r = 0, len(matrix[0])
        t, b = 0, len(matrix)
        while l < r and t < b:
            for i in range(l, r):
                ans.append(matrix[t][i])
            if t + 1 == b:
                break
            for i in range(t + 1, b):
                ans.append(matrix[i][r - 1])
            if l + 1 == r:
                break
            for i in range(r - 2, l - 1, -1):
                ans.append(matrix[b - 1][i])
            for i in range(b - 2, t, -1):
                ans.append(matrix[i][l])
            l += 1
            r -= 1
            t += 1
            b -= 1
        return ans

if __name__ == '__main__':
    # matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    # matrix = [[1, 2, 3, 4]]
    matrix = [[7], [6], [9]]
    sol = Solution()
    spiralMatrix = sol.spiralOrder(matrix)
    print(spiralMatrix)
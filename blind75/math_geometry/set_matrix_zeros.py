from typing import List

class Solution(object):
    def setZeroes(self, matrix: List[List[int]]) -> None:
        temp = False
        for r in range(len(matrix)):
            for c in range(len(matrix[0])):
                if matrix[r][c] == 0:
                    if r == 0:
                        temp = True
                    else:
                        matrix[r][0] = 0
                    matrix[0][c] = 0
        
        for r in range(1, len(matrix)):
            for c in range(1, len(matrix[0])):
                if matrix[r][0] == 0 or matrix[0][c] == 0:
                    matrix[r][c] = 0
        
        if matrix[0][0] == 0:
            for r in range(len(matrix)):
                matrix[r][0] = 0
        
        if temp:
            for c in range(len(matrix[0])):
                matrix[0][c] = 0

if __name__ == '__main__':
    # matrix = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    sol = Solution()
    sol.setZeroes(matrix)
    print(matrix)
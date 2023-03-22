from typing import List


class Solution:
    def canPartition(self, arr: List[int]) -> bool:
        n = len(arr)
        sum = 0
        for i in range(n):
            sum += arr[i]
        if sum % 2 != 0:
            return False
        dp = [[-1]*(sum+1) for _ in range(n+1)]
        return self.isSubsetSum(arr, n, sum // 2, dp)

    def isSubsetSum(self, arr: List[int],
                    n: int, sum: int, dp) -> bool:
        if (sum == 0):
            return True
        if (n == 0 and sum != 0):
            return False
        if (dp[n][sum] != -1):
            return dp[n][sum]
        if (arr[n - 1] > sum):
            return self.isSubsetSum(arr, n - 1, sum, dp)
        
        dp[n][sum] = self.isSubsetSum(
            arr, n - 1, sum, dp) or self.isSubsetSum(arr, n - 1, sum - arr[n - 1], dp)
        return dp[n][sum]


if __name__ == "__main__":
    nums = [1, 5, 11, 5]
    print(Solution().canPartition(nums))

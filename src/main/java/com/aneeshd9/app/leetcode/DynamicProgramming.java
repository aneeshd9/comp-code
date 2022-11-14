package com.aneeshd9.app.leetcode;

import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.Map.Entry;

public class DynamicProgramming {
    public int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }

    public int fib(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;

        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    public int climbStairs(int n) {
        int[] dp = new int[n + 1];
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] dp = new int[n + 1];
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= n; ++i) {
            dp[i] = Math.min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }

    public int rob(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            dp[i] = Math.max(nums[i - 1] + dp[i - 2], dp[i - 1]);
        }
        return dp[n];
    }

    public int rob2(int[] nums) {
        int n = nums.length;
        if (n == 1) return nums[0];
        else {
            int[] leftCopy = new int[n - 1];
            int[] rightCopy = new int[n - 1];
            System.arraycopy(nums, 0, leftCopy, 0, n - 1);
            System.arraycopy(nums, 1, rightCopy, 0, n - 1);
            return Math.max(rob(leftCopy), rob(rightCopy));
        }
    }

    public int deleteAndEarn(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        Map<Integer, Integer> counts = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            if (counts.containsKey(nums[i])) {
                counts.put(nums[i], counts.get(nums[i]) + 1);
            } else {
                counts.put(nums[i], 1);
            }
        }
        Set<Integer> keySetCopy = new HashSet<>(counts.keySet());
        for (int k: keySetCopy) {
            if (k - 1 > 0 && !counts.containsKey(k - 1)) {
                counts.put(k - 1, 0);
            }
            if (!counts.containsKey(k + 1)) {
                counts.put(k + 1, 0);
            }
        }
        int[] filteredNums = new int[counts.size()];
        int i = 0;
        for (Entry<Integer, Integer> entry: counts.entrySet()) {
            filteredNums[i] = entry.getKey() * entry.getValue();
            i += 1;
        }
        return rob(filteredNums);
    }
}

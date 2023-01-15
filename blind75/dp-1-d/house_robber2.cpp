#include <vector>

class Solution {
public:
    int rob(std::vector<int> &nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        } else {
            std::vector<int> left (nums.begin() + 1, nums.end());
            std::vector<int> right (nums.begin(), nums.end() - 1);
            return std::max(rob1(left), rob1(right));
        }
    }

    int rob1(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];
    }
};
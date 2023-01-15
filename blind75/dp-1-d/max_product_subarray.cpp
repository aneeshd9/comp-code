#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(2, 0));
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = std::min(nums[i], std::min(nums[i] * dp[i - 1][0], nums[i] * dp[i - 1][1]));
            dp[i][1] = std::max(nums[i], std::max(nums[i] * dp[i - 1][0], nums[i] * dp[i - 1][1]));
        }
        int ans = nums[0];
        for (int i = 0; i < n; ++i) {
            ans = std::max(ans, dp[i][1]);
        }
        return ans;
    }
};
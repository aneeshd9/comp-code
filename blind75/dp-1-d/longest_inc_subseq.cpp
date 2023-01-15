#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], 1 + dp[j]);
                }
            }
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};
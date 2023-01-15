#include <vector>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, 999999);
        dp[0] = 1;
        for (int i = 1; i <= amount; ++i) {
            for (auto denom: coins) {
                if (i - denom >= 0) {
                    dp[i] = std::min(dp[i], 1 + dp[i - denom]);
                }
            }
        }
        if (dp[amount] < 999999) {
            return dp[amount] - 1;
        } else {
            return -1;
        }
    }
};
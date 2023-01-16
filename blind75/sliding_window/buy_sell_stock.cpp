#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        int window_left = 0;
        int window_right = 1;
        int ans = 0;
        while (window_right < prices.size()) {
            if (prices[window_left] < prices[window_right]) {
                ans = std::max(ans, prices[window_right] - prices[window_left]);
                window_right += 1;
            } else {
                window_left = window_right;
                window_right += 1;
            }
        }
        return ans;
    }
};
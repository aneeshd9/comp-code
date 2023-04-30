#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int left = 0;
    int right = 1;
    int ans = 0;
    while (right < prices.size()) {
      if (prices[left] < prices[right]) {
        ans = std::max(ans, prices[right] - prices[left]);
        right++;
      } else {
        left = right;
        right++;
      }
    }
    return ans;
  }
};

#include <algorithm>
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    int ans = nums[0];
    int currentMax = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      int num = nums[i];
      currentMax = std::max(currentMax + num, num);
      ans = std::max(currentMax, ans);
    }
    return ans;
  }
};

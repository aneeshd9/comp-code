#include <algorithm>
#include <vector>

class Solution {
public:
  bool canJump(std::vector<int> &nums) {
    int maxReachable = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i <= maxReachable) {
        maxReachable = std::max(maxReachable, i + nums[i]);
      }
    }
    if (nums.size() - 1  <= maxReachable) return true;
    else return false;
  }
};

#include<vector>
#include<map>
#include<cassert>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::map<int, int> idxs;
    std::vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
      idxs.insert({ nums[i], i });
    }
    for (int i = 0; i < nums.size(); ++i) {
      int other = target - nums[i];
      auto it = idxs.find(other);
      if (it != idxs.end() && it->second != i) {
        ans.push_back(i);
        ans.push_back(idxs.find(other)->second);
        break;
      }
    }
    
    // One solution should always exist.
    assert(ans.size() == 2);

    return ans;
  }
};

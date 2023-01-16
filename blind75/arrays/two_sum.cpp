#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::map<int, int> locs;
        std::vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (locs.find(target - nums[i]) != locs.end()) {
                ans.push_back(i);
                ans.push_back(locs[target - nums[i]]);
                return ans;
            }
            locs.insert({nums[i], i});
        }
        return ans;
    }
};
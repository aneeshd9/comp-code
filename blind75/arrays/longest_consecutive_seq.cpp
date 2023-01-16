#include <vector>
#include <set>

class Solution {
public:
    int longestConsecutive(std::vector<int> &nums) {
        std::set<int> nums_set(nums.begin(), nums.end());
        int ans = 0;
        for (auto num: nums) {
            if (nums_set.find(num - 1) == nums_set.end()) {
                int len = 1;
                while (nums_set.find(num + len) != nums_set.end()) {
                    len += 1;
                }
                ans = std::max(ans, len);
            }
        }
        return ans;
    }
};
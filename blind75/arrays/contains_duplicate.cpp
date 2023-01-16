#include <vector>
#include <set>

class Solution {
public:
    bool containsDuplicate(std::vector<int> &nums) {
        std::set<int> unique;
        for(int i = 0; i < nums.size(); ++i) {
            if (unique.find(nums[i]) == unique.end()) {
                unique.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;

            int j = i + 1, k = nums.size() - 1;

            while (j < k) {
                if (j == i) ++j;
                else if (k == i) --k;

                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) ++j;
                else if (sum > 0) --k;
                else {
                    ans.push_back(std::vector<int> {nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) ++j;
                    while (j < k && nums[k - 1] == nums[k]) --k;
                    ++j;
                    --k;
                }
            }
        }
        return ans;
    }
};
#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
        std::map<int, int> counts;
        for (auto num: nums) {
            counts[num] += 1;
        }
        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            buckets[it->second].push_back(it->first);
        }
        std::vector<int> ans;
        for (auto it = buckets.rbegin(); it != buckets.rend(); ++it) {
            if (ans.size() >= k) {
                break;
            }
            if (!it->empty()) {
                ans.insert(ans.end(), it->begin(), it->end());
            }
        }
        return ans;
    }
};
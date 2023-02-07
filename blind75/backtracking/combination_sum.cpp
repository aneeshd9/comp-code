#include <vector>
#include <algorithm>

class Solution {
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                               int target) {
    std::vector<int> path;
    std::vector<std::vector<int>> ans;
    backtrack(candidates,
              target,
              path,
              ans,
              0,
              0);
    return ans;
  }

  void backtrack(std::vector<int> &candidates,
                 int target,
                 std::vector<int> &path,
                 std::vector<std::vector<int>> &ans,
                 int currentSum,
                 int candidatesIndex) {
    if (currentSum == target) {
      ans.push_back(path);
      return;
    }

    if (currentSum > target) {
      return;
    }

    for (int i = candidatesIndex; i < candidates.size(); ++i) {
      path.push_back(candidates[i]);
      backtrack(candidates, target, path, ans, currentSum + candidates[i], i);
      path.pop_back();
    }
  }
};

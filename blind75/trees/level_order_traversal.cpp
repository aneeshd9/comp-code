#include "TreeNode.hpp"

#include <utility>
#include <vector>
#include <queue>

class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> ans;

    std::queue<std::pair<int, TreeNode*>> q;
    q.push(std::make_pair(1, root));

    while (!q.empty()) {
      int top_level = q.front().first;
      TreeNode *top = q.front().second;
      q.pop();

      if (top != nullptr) {
        if (ans.size() < top_level) {
          ans.push_back(std::vector<int>());
        }
        ans[top_level - 1].push_back(top->val);
        q.push(std::make_pair(top_level + 1, top->left));
        q.push(std::make_pair(top_level + 1, top->right));
      }
    }
    
    return ans;
  }
};

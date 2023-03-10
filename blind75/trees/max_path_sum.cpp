#include "TreeNode.hpp"

#include <climits>
#include <algorithm>

class Solution {
public:
  int maxPathSum(TreeNode *root) {
    int ans = INT_MIN;
    maxUtil(root, ans);
    return ans;
  }

private:
  int maxUtil(TreeNode *root, int &overallMax) {
    if (root == nullptr) return 0;

    int leftMax = maxUtil(root->left, overallMax);
    int rightMax = maxUtil(root->right, overallMax);

    int rootMax = std::max(root->val, root->val + std::max(leftMax, rightMax));

    overallMax = std::max(overallMax, std::max(rootMax, leftMax + root->val + rightMax));

    return rootMax;
  }
};

#include "TreeNode.hpp"
#include <algorithm>

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    else if (root->left == nullptr && root->right == nullptr) return 1;
    else return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
  }
};

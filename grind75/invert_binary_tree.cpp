#include "TreeNode.hpp"

class Solution {
public:
  TreeNode *invertTree(TreeNode  *root) {
    if (root == nullptr) return nullptr;
    else {
      TreeNode *leftInverted = invertTree(root->left);
      TreeNode *rightInverted = invertTree(root->right);
      root->left = rightInverted;
      root->right = leftInverted;
      return root;
    }
  }
};

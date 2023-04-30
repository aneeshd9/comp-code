#include "TreeNode.hpp"
#include <algorithm>

class Solution {
public:
  int diameterOfBinaryTree(TreeNode *root) {
    int height = 0;
    return diamaterHelper(root, height) - 1;
  }

private:
  int diamaterHelper(TreeNode *root, int &height) {
    if (root == nullptr) {
      height = 0;
      return 0;
    }

    int leftHeight = 0;
    int rightHeight = 0;
    int leftDiamater = diamaterHelper(root->left, leftHeight);
    int rightDiameter = diamaterHelper(root->right, rightHeight);

    height = std::max(leftHeight, rightHeight) + 1;
    return std::max(std::max(leftDiamater, rightDiameter), leftHeight + rightHeight + 1);
  }
};
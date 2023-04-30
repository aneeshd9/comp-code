#include "TreeNode.hpp"
#include <cmath>
#include <algorithm>

class Solution {
public:
  bool isBalanced(TreeNode *t) {
    int h = 0;
    return isBalancedHelper(t, h);
  }
private:
  bool isBalancedHelper(TreeNode *root, int &height) {
    if (root == nullptr) {
      height = 0;
      return true;
    }
    else {
      int leftHeight = 0;
      int rightHeight = 0;
      bool leftBalanced = isBalancedHelper(root->left, leftHeight);
      bool rightBalanced = isBalancedHelper(root->right, rightHeight);
      
      height = std::max(leftHeight, rightHeight) + 1;
      return leftBalanced && rightBalanced && std::abs(leftHeight - rightHeight) <= 1;
    }
  }
};

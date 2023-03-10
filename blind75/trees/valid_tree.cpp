#include "TreeNode.hpp"

#include <iostream>

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    if (root == nullptr) return true;
    TreeNode *maxLeft = max(root->left);
    TreeNode *minRight = min(root->right);

    if (maxLeft != nullptr && maxLeft->val >= root->val) return false;
    if (minRight != nullptr && minRight->val <= root->val) return false;

    return isValidBST(root->left) && isValidBST(root->right);
  }

private:
  TreeNode *max(TreeNode *root) {
    if (root == nullptr) return nullptr;
    if (root->left == nullptr and root->right == nullptr) {
      return root;
    } else {
      TreeNode *maxLeft = max(root->left);
      TreeNode *maxRight = max(root->right);

      TreeNode *ans = root;
      if (maxLeft != nullptr && maxLeft->val > ans->val) ans = maxLeft;
      if (maxRight != nullptr && maxRight->val > ans->val) ans = maxRight;
      return ans;
    }
  }

  TreeNode *min(TreeNode *root) {
    if (root == nullptr) return nullptr;
    if (root->left == nullptr and root->right == nullptr) {
      return root;
    } else {
      TreeNode *minLeft = min(root->left);
      TreeNode *minRight = min(root->right);

      TreeNode *ans = root;
      if (minLeft != nullptr && minLeft->val < ans->val) ans = minLeft;
      if (minRight != nullptr && minRight->val < ans->val) ans = minRight;
      return ans;
    }
  }
};

int main (int argc, char *argv[]) {
  TreeNode *root = new TreeNode(5,
                                new TreeNode(1),
                                new TreeNode(4, new TreeNode(3), new TreeNode(6)));
  bool ans = Solution().isValidBST(root);
  std::cout << ans << std::endl;
  return 0;
}

#include "TreeNode.hpp"

#include <vector>

class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    std::vector<int> order;
    inorder(root, order);
    return order[k - 1];
  }

private:
  void inorder(TreeNode *root, std::vector<int> &order) {
    if (root == nullptr) return;
    inorder(root->left, order);
    order.push_back(root->val);
    inorder(root->right, order);
  }
};

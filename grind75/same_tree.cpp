#include "TreeNode.hpp"

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) return true;
    else if (p == nullptr) return false;
    else if (q == nullptr) return false;
    else return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};
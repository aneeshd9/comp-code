#include "TreeNode.hpp"

class Solution {
public:
  bool isSubtree(TreeNode *root, TreeNode *subroot) {
    if (root == nullptr && subroot == nullptr) return true;
    else if (root == nullptr) return false;
    else if (isSameTree(root, subroot)) return true;
    else return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
  }

  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) return true;
    else if (p == nullptr && q != nullptr) return false;
    else if (p != nullptr && q == nullptr) return false;
    else if (p->val == q->val) return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    else return false;
  }
};

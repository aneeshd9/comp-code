#include "TreeNode.hpp"

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr) return nullptr;
    if (root == p || root == q) return root;
    TreeNode *left_lca = lowestCommonAncestor(root->left, p, q);
    TreeNode *right_lca = lowestCommonAncestor(root->right, p, q);

    if (left_lca && right_lca) return root;
    return (left_lca != nullptr) ? left_lca : right_lca;
  }
};

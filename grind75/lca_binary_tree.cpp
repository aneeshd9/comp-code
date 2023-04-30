#include "TreeNode.hpp"

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode  *q) {
    if (root == nullptr) return nullptr;
    if (root == p || root == q) return root;
    TreeNode *leftLca = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightLca = lowestCommonAncestor(root->right, p, q);
    if (leftLca && rightLca) return root;
    return (leftLca != nullptr) ? leftLca : rightLca;
  }
};

#include "TreeNode.hpp"

class Solution {
public:
  TreeNode *invertTree(TreeNode *head) {
    if (head == nullptr) return head;

    TreeNode *invertedLeft = invertTree(head->left);
    TreeNode *invertedRight = invertTree(head->right);
    head->left = invertedRight;
    head->right = invertedLeft;
    return head;
  }
};

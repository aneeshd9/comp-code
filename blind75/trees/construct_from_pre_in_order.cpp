#include "TreeNode.hpp"

#include <vector>

class Solution {
public:
  Solution() { rootIndex = 0; }

  TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    return build(preorder, inorder, 0, inorder.size() - 1);
  }

private:
  int rootIndex = 0;

  TreeNode *build(std::vector<int> &preorder, std::vector<int> &inorder,
                  int i, int j) {
    if (i > j) return nullptr;

    TreeNode *root = new TreeNode(preorder[rootIndex]);
    
    int k = i;
    for (int idx = i; idx <= j; ++idx) {
      if (preorder[rootIndex] == inorder[idx]) {
        k = idx;
        break;
      }
    }
    rootIndex++;

    root->left = build(preorder, inorder, i, k - 1);
    root->right = build(preorder, inorder, k + 1, j);
    return root;
  }
};

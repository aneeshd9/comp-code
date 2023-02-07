#ifndef __TREENODE_H__
#define __TREENODE_H__

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r) {}
};

#endif // !DEBUG

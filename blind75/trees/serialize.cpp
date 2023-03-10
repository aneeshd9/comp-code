#include "TreeNode.hpp"
#include <sstream>
#include <string>

class Codec {
public:
  std::string serialize(TreeNode *root) {
    std::ostringstream out;
    encode(root, out);
    return out.str();
  }

  TreeNode *deserialize(std::string data) {
    std::istringstream in(data);
    return decode(in);
  }
private:
  void encode(TreeNode *root, std::ostringstream &out) {
    if (root == nullptr) {
      out << "null ";
      return;
    }

    out << root->val << " ";
    encode(root->left, out);
    encode(root->right, out);
  }

  TreeNode *decode(std::istringstream &in) {
    std::string val;
    in >> val;

    if (val == "null") return nullptr;

    TreeNode *root = new TreeNode(std::stoi(val));
    root->left = decode(in);
    root->right = decode(in);

    return root;
  }
};

#include "Node.hpp"

#include <map>

using std::map;
using std::vector;

class Solution {
public:
  Node *cloneGraph(Node *node) {
    map<int, Node*> visited;
    return dfs(visited, node);
  }

private:
  Node *dfs(map<int, Node*> &visited, Node *node) {
    if (node == nullptr) return nullptr;
    Node *copy = new Node(node->val);
    visited[copy->val] = copy;

    for (Node *neighbor: node->neighbors) {
      if (visited.find(neighbor->val) == visited.end())
        copy->neighbors.push_back(dfs(visited, neighbor));
      else
        copy->neighbors.push_back(visited.find(neighbor->val)->second);
    }

    return copy;
  }
};

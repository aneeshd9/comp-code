#include <ostream>
#include <queue>
#include <iostream>
#include <utility>
#include <vector>

using std::cout;
using std::pair;
using std::queue;
using std::vector;
using std::endl;

class Solution {
public:
  bool validTree(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n, vector<int>());

    for (int i = 0; i < edges.size(); ++i) {
      int m = edges[i][0];
      int n = edges[i][1];
      graph[m].push_back(n);
      graph[n].push_back(m);
    }

    vector<bool> visited(n, false);
    queue<pair<int, int>> q;
    q.push({0, -1});
    visited[0] = true;

    while (!q.empty()) {
      pair<int, int> top = q.front();
      q.pop();

      int current = top.first;
      int parent = top.second;

      for (int neighbor: graph[current]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push({neighbor, current});
        }
        else {
          if (neighbor != parent) return false;
        }
      }
    }

    for (bool visit_status: visited) {
      if (!visit_status) return false;
    }

    return true;
  }
};


int main(void) {
  int n = 5;
  vector<vector<int>> edges;
  edges.push_back({0, 1});
  edges.push_back({0, 2});
  edges.push_back({0, 3});
  edges.push_back({1, 4});
  cout << Solution().validTree(n, edges) << endl;
  return 0;
}

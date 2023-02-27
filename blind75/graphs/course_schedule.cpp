#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prereqs) {
    vector<vector<int>> adj_list (numCourses, vector<int>());
    vector<int> in_deg(numCourses, 0);
    for (vector<int> &prereq: prereqs) {
      adj_list[prereq[1]].push_back(prereq[0]);
      in_deg[prereq[0]]++;
    }

    vector<int> order;
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (in_deg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
      int top = q.front();
      q.pop();
      order.push_back(top);

      for (int neighbor: adj_list[top]) {
        in_deg[neighbor]--;
        if (in_deg[neighbor] == 0) q.push(neighbor);
      }
    }

    if (order.size() == numCourses) return true;
    else return false;
  }
};

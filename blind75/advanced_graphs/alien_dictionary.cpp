#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <queue>

using std::map;
using std::min;
using std::string;
using std::vector;
using std::queue;

class Solution {
public:
  string alienOrder(vector<string> &words) {
    map<char, vector<char>> graph;
    map<char, int> in_deg;

    for (string &word: words) {
      for (char &c: word) {
        graph.insert({c, vector<char>()});
        in_deg.insert({c, 0});
      }
    }

    for (int i = 0; i < words.size() - 1; ++i) {
      int comp_len = min(words[i].size(), words[i + 1].size());
      int j = 0;
      while (j < comp_len && words[i][j] == words[i + 1][j]) j++;
      if (j < comp_len) {
        graph[words[i][j]].push_back(words[i + 1][j]);
        in_deg[words[i + 1][j]]++;
      }
    }

    int n = graph.size();
    queue<char> q;

    for (auto it = in_deg.begin(); it != in_deg.end(); ++it) {
      if (it->second == 0) q.push(it->first);
    }

    string ans {""};
    while (!q.empty()) {
      char top = q.front();
      q.pop();

      ans += top;

      for (char neighbor: graph[top]) {
        in_deg[neighbor]--;
        if (in_deg[neighbor] == 0) q.push(neighbor);
      }
    }

    if (ans.size() == n) return ans;
    else return "";
  }
};

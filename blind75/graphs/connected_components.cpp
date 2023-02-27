#include <vector>

using std::vector;

class UnionFind {
private:
  int count;
  vector<int> parent;
  vector<int> rank;

public:
  UnionFind(int n) {
    this->count = n;
    this->parent = vector<int>(n, -1);
    this->rank = vector<int>(n, 0);

    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }
  
  int get_count() { return count; }

  int find(int elem) {
    while (elem != parent[elem]) {
      parent[elem] = parent[parent[elem]];
      elem = parent[elem];
    }
    return elem;
  }

  void do_union(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);

    if (root_a != root_b) {
      if (rank[root_a] < rank[root_b]) parent[root_a] = root_b;
      else if (rank[root_a] > rank[root_b]) parent[root_b] = root_a;
      else {
        parent[root_b] = root_a;
        rank[root_a]++;
      }
      count--;
    }
  }

  bool connected(int a, int b) {
    return find(a) == find(b);
  }
};

class Solution {
public:
  int countComponents(int n, vector<vector<int>> &edges) {
    UnionFind uf(n);
    for (int i = 0; i < edges.size(); ++i) {
      int a = edges[i][0];
      int b = edges[i][1];
      uf.do_union(a, b);
    }
    return uf.get_count();
  }
};

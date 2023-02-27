#include <vector>

using std::vector;

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int islands = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1' && !visited[i][j])  {
          dfs(grid, visited, i, j);
          islands++;
        }
      }
    }

    return islands;
  }

private:
  void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited,
           int si, int sj) {
    int m = grid.size();
    int n = grid[0].size();

    visited[si][sj] = true;

    if (si + 1 < m && grid[si + 1][sj] == '1' && !visited[si + 1][sj])
      dfs(grid, visited, si + 1, sj);
    if (si - 1 >= 0 && grid[si - 1][sj] == '1' && !visited[si - 1][sj])
      dfs(grid, visited, si - 1, sj);
    if (sj + 1 < n && grid[si][sj + 1] == '1' && !visited[si][sj + 1])
      dfs(grid, visited, si, sj + 1);
    if (sj - 1 >= 0 && grid[si][sj - 1] == '1' && !visited[si][sj - 1])
      dfs(grid, visited, si, sj - 1);
  }
};

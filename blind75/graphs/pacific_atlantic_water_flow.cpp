#include <vector>

using std::vector;

class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int m = heights.size();
    int n = heights[0].size();

    vector<vector<bool>> visited_pacific(m, vector<bool>(n, false));
    vector<vector<bool>> visited_atlantic(m, vector<bool>(n, false));

    for (int r = 0; r < m; ++r) {
      dfs(heights, visited_pacific, r, 0);
      dfs(heights, visited_atlantic, r, n - 1);
    }

    for (int c = 0; c < n; ++c) {
      dfs(heights, visited_pacific, 0, c);
      dfs(heights, visited_atlantic, m - 1, c);
    }

    vector<vector<int>> ans;
    for (int r = 0; r < m; ++r) {
      for (int c = 0; c < n; ++c) {
        if (visited_pacific[r][c] && visited_atlantic[r][c])
          ans.push_back(vector<int> {r, c});
      }
    }

    return ans;
  }

private:
  void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited,
           int i, int j) {

    int m = grid.size();
    int n = grid[0].size();

    visited[i][j] = true;

    if (i + 1 < m && !visited[i + 1][j] && grid[i][j] <= grid[i + 1][j])
      dfs(grid, visited, i + 1, j);
    if (i - 1 >= 0 && !visited[i - 1][j] && grid[i][j] <= grid[i - 1][j])
      dfs(grid, visited, i - 1, j);
    if (j + 1 < n && !visited[i][j + 1] && grid[i][j] <= grid[i][j + 1])
      dfs(grid, visited, i, j + 1);
    if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j] <= grid[i][j - 1])
      dfs(grid, visited, i, j - 1);
  }
};

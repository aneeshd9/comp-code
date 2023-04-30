#include <utility>
#include <vector>
#include <queue>

class Solution {
public:
  std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image, int sr, int sc, int color) {
    int height = image.size();
    int width = image[0].size();

    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
    std::vector<std::vector<int>> ans(height, std::vector<int>(width, 0));

    std::queue<std::pair<int, int>> q;
    q.push({ sr, sc });

    while (!q.empty()) {
      int top_r = q.front().first;
      int top_c = q.front().second;
      q.pop();
      ans[top_r][top_c] = color;
      visited[top_r][top_c] = true;
      
      if (inRange(top_r + 1, top_c, height, width) && !visited[top_r + 1][top_c] && sameColor(top_r + 1, top_c, top_r, top_c, image)) {
        q.push({ top_r + 1, top_c });
      }
      if (inRange(top_r - 1, top_c, height, width) && !visited[top_r - 1][top_c] && sameColor(top_r - 1, top_c, top_r, top_c, image)) {
        q.push({ top_r - 1, top_c });
      }
      if (inRange(top_r, top_c + 1, height, width) && !visited[top_r][top_c + 1] && sameColor(top_r, top_c + 1, top_r, top_c, image)) {
        q.push({ top_r, top_c + 1 });
      }
      if (inRange(top_r, top_c - 1, height, width) && !visited[top_r][top_c - 1] && sameColor(top_r, top_c - 1, top_r, top_c, image)) {
        q.push({ top_r, top_c - 1 });
      }
    }

    for (int r = 0; r < height; ++r) {
      for (int c = 0; c < width; ++c) {
        if (!visited[r][c]) {
          ans[r][c] = image[r][c];
        }
      }
    }

    return ans;
  }

private:
  bool inRange(int r, int c, int h, int w) {
    return r >= 0 && r < h && c >= 0 && c < w;
  }

  bool sameColor(int r1, int c1, int r2, int c2, std::vector<std::vector<int>> &image) {
    return image[r1][c1] == image[r2][c2];
  }
};

#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int longestCommonSubsequence(std::string text1, std::string text2) {
    int n = text1.size();
    int m = text2.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = std::max(dp[i][j], 1 + dp[i - 1][j - 1]);
        }
        dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
        dp[i][j] = std::max(dp[i][j], dp[i][j - 1]);
      }
    }
    
    return dp[n][m];
  }
};

#include <vector>
#include <string>

class Solution {
public:
    int numDecodings(std::string s) {
        int n = s.size();
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int single = std::stoi(s.substr(i - 1, 1));
            if (single > 0 && single < 27) {
                dp[i] += dp[i - 1];
            }
            if (i - 2 >= 0) {
                int couple = std::stoi(s.substr(i - 2, 2));
                if (couple > 0 && couple < 27 && couple != single) {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[n];
    }
};
#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string> &words) {
        int n = s.size();
        std::vector<bool> dp(n, false);
        std::unordered_set<std::string> words_set(words.begin(), words.end());
        if (words_set.find(s.substr(0, 1)) != words_set.end()) {
            dp[0] = true;
        }
        for (int i = 1; i < n; ++i) {
            int start = i;
            while (start >= 0) {
                std::string current_word = s.substr(start, i - start + 1);
                if (start - 1 >= 0 && dp[start - 1] && words_set.find(current_word) != words_set.end()) {
                    dp[i] = true;
                    break;
                } else if (start == 0 && words_set.find(current_word) != words_set.end()) {
                    dp[i] = true;
                    break;
                }
                start--;
            }
        }
        return dp[n - 1];
    }
};
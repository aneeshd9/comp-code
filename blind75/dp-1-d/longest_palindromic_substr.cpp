#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::string ans {""};
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            int a = i, b = i;
            while (a >= 0 && b < s.size() && s[a] == s[b]) {
                if (b - a + 1 >= maxLen) {
                    ans = s.substr(a, b - a + 1);
                    maxLen = b - a + 1;
                }
                a--;
                b++;
            }

            a = i, b = i + 1;
            if (!(b < s.size())) {
                continue;
            }
            while (a >= 0 && b < s.size() && s[a] == s[b]) {
                if (b - a + 1 >= maxLen) {
                    ans = s.substr(a, b - a + 1);
                    maxLen = b - a + 1;
                }
                a--;
                b++;
            }
        }
        return ans;
    }
};
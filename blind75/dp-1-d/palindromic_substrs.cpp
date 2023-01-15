#include <string>

class Solution {
public:
    int countSubstrings(std::string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            int a = i, b = i;
            while (a >= 0 && b < s.size() && s[a] == s[b]) {
                count++;
                a--;
                b++;
            }

            a = i, b = i + 1;
            if (!(b < s.size())) {
                continue;
            }
            while (a >= 0 && b < s.size() && s[a] == s[b]) {
                count++;
                a--;
                b++;
            }
        }
        return count;
    }
};
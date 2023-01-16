#include <string>
#include <set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int window_left = 0;
        int window_right = 0;
        std::set<char> char_set;
        int ans = 0;
        while (window_right < s.size()) {
            while (char_set.find(s[window_right]) != char_set.end()) {
                char_set.erase(s[window_left]);
                window_left += 1;
            }
            ans = std::max(ans, window_right - window_left + 1);
            char_set.insert(s[window_right]);
            window_right += 1;
        }
        return ans;
    }
};
#include <string>
#include <map>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        std::map<char, int> char_count;
        for (auto ch: t) char_count[ch] += 1;
        int window_left = 0, window_right = 0;
        int start = 0;
        int min_length = INT_MAX;
        int counter = t.size();

        while (window_right < s.size()) {
            if (char_count[s[window_right]] > 0) {
                counter -= 1;
            }
            char_count[s[window_right]] -= 1;
            window_right += 1;

            while (counter == 0) {
                if (min_length > window_right - window_left) {
                    min_length = window_right - window_left;
                    start = window_left;
                }
                char_count[s[window_left]] += 1;
                if (char_count[s[window_left]] > 0) {
                    counter += 1;
                }
                window_left += 1;
            }
        }

        if (min_length == INT_MAX) return "";
        else return s.substr(start, min_length);
    }
};
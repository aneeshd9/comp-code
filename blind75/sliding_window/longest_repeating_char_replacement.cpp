#include <string>
#include <vector>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> counts(26, 0);
        int max_count = 0;
        int window_left = 0;
        int window_right = 0;
        int ans = 0;
        while (window_right < s.size()) {
            counts[s[window_right] - 'A'] += 1;
            max_count = std::max(max_count, counts[s[window_right] - 'A']);
            if (window_right - window_left + 1 - max_count > k) {
                counts[s[window_left] - 'A'] -= 1;
                window_left += 1;
            }
            ans = std::max(ans, window_right - window_left + 1);
            window_right += 1;
        }
        return ans;
    }
};